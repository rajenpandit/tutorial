#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#define EMPLOYEE_FILE  "Employee.txt"

typedef struct Employee{
    int id;
    char name[20];
    double salary;
    double bonus;
} Employee;

int writeEmployee(Employee* emp, size_t n_employee)
{
    FILE* fp = fopen(EMPLOYEE_FILE, "wb");
    if(fp == NULL)
        return -1;
    int i;
    for( i=0; i<n_employee; ++i )
    {
        emp[i].id = i+1;
        size_t n = fwrite(emp+i, sizeof(Employee), 1, fp);
        if(n == 0)
            return -1;
    }
    fclose(fp);
    return i;
}


int readEmployee(Employee* emp, size_t n_employee)
{
    FILE *fp = fopen(EMPLOYEE_FILE, "rb");
    if(fp == NULL){
        return -1;
    }
    int i=0;
    for( i=0 ; i<n_employee; ++i)
    {
        size_t n = fread(emp+i, sizeof(Employee), 1, fp);
        if( (n==0) && (feof(fp) != 0))
        {
            break;
        }
    }
    fclose(fp);
    return i;
}

int getNumberOfEmployee(){
    struct stat st;
    int fd = open(EMPLOYEE_FILE, O_RDONLY);
    if(fd == -1)
        return -1;
    if(fstat(fd, &st) != 0){
        return -1;
    }
    return st.st_size/sizeof(Employee);
}
int readEmployeeDetails(Employee** emp_pp)
{
   int n_employee = getNumberOfEmployee();
   Employee* emp = malloc(sizeof(Employee) * n_employee);
   readEmployee(emp,n_employee);
   *emp_pp = emp;
   return n_employee;
}
int printEmployee(Employee emp[], int n_employee){

    for(int i=0; i<n_employee; ++i)
    {
        Employee *emp_p = emp + i ;
        printf("Id:%d\n",emp_p->id);
        printf("Name:%s\n",emp_p->name);
        printf("Salary:%lf\n",emp_p->salary);
        printf("Bonus:%lf\n",emp_p->bonus);
        printf("-----------------------------\n");
    }
    return 0;
}

/* Read employee details from user */
Employee getEmployeeDetails(){
    Employee emp;
    printf("Enter Employee Id:");
    scanf("%d",&emp.id);
    printf("Enter Employee Name:");
    scanf("%s",emp.name);
    printf("Enter Employee Salary:");
    scanf("%lf",&emp.salary);
    printf("Enter Employee Bonus:");
    scanf("%lf",&emp.bonus);
    return emp;
}

void insertAtIndex(Employee emp[], int nElements, int index, Employee newEmp)
{
    // move all elements from last by one till index pos.
    // emp = [3|4|2|6], nElements = 4, index=1 , newEmp=1 
    if(index > nElements)
        index = nElements;
    for(int i=nElements; i>index; --i)
    {
        emp[i] = emp[i-1];
    }
    // emp = [3|4|4|2|6]
    emp[index] =  newEmp;
    // emp = [3|1|4|2|6]
}

int addEmployee(Employee newEmp, int index){
    int n_employee;
    n_employee = getNumberOfEmployee();

    Employee emp[n_employee+1];
    readEmployee(emp,n_employee);
    insertAtIndex(emp, n_employee, index, newEmp);
    writeEmployee(emp,n_employee+1);
    return 0;
}

int deleteEmployee(){
    int emp_id;
    int n_employee = getNumberOfEmployee();
    if(n_employee <= 0)
        return -1;
    Employee emp[n_employee];
    readEmployee(emp,n_employee);
    printEmployee(emp, n_employee);
    printf("Enter ID to delete:");
    scanf("%d",&emp_id);

    for(int i = emp_id-1; i<n_employee-1; ++i)
    {
        emp[i] = emp[i+1];
    }
    n_employee -= 1;
    writeEmployee(emp,n_employee);
    return 0;
}

int updateEmployee()
{
    int emp_id;
    int n_employee = getNumberOfEmployee();
    if(n_employee <= 0)
        return -1;
    Employee emp[n_employee];
    readEmployee(emp,n_employee);
    printEmployee(emp, n_employee);
    printf("Enter ID to update:");
    scanf("%d",&emp_id);
    if(!(emp_id > 0 && emp_id <= n_employee))
        return -1;
    Employee *emp_p = emp + (emp_id -1);
    printf("1. update salary\n 2. update bonus\n 3. update salary and bonus\n");
    int choice;
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("Enter new salary:");
        scanf("%lf",&emp_p->salary);
        break;
    case 2:
        printf("Enter new bonus:");
        scanf("%lf",&emp_p->bonus);
        break;
    case 3:
        printf("Enter new salary:");
        scanf("%lf",&emp_p->salary);
        printf("Enter new bonus:");
        scanf("%lf",&emp_p->bonus);
        break;
    default:
        break;
    }
    return writeEmployee(emp,n_employee);
}

int main(){
    int choice;
    do{
        printf(" 1. Add new\n 2. Modify\n 3. Delete\n 4. Print\n");
        scanf("%d",&choice);
        switch (choice)
        {
        int index;
        int n_employee;
        Employee* emp_p;
        case 1:
            printf("Enter index:");
            scanf("%d",&index);
            addEmployee(getEmployeeDetails(), index);
            break;
        case 2:
            updateEmployee();
            break;
        case 3: 
            deleteEmployee();
            break;
        case 4:
            emp_p = NULL;
            n_employee = readEmployeeDetails(&emp_p);
            printEmployee(emp_p, n_employee);
            if(emp_p != NULL)
                free(emp_p);
            break;
        case 5:
            break;
        default:
            break;
        }
    }
    while(choice != 5);
#if 0 //test
    Employee emp[2] = {
        {1,"Rohan", 100.0, 5.0},
        {1, "Mohan", 200.0, 10.0}
    };
    if(writeEmployee(emp, 2) == -1)
        printf("wirte error\n");
    else   
        printf("write successful\n");

    printf("Total Employee:%d\n", getNumberOfEmployee());

    Employee newEmp = {3,"Rahul", 300.0, 40.0}; //getEmployeeDetails();
    addEmployee(newEmp,10);
    printf("Total Employee:%d\n", getNumberOfEmployee());
    
    int n_emplyee = getNumberOfEmployee();
    Employee emp1[n_emplyee];
    readEmployee(emp1, n_emplyee);
    printEmployee(emp1, n_emplyee);
#if 0 // delete   
    deleteEmployee();
    Employee emp2[n_emplyee-1];
    readEmployee(emp1,n_emplyee-1);
    printEmployee(emp1,n_emplyee-1);
#endif
    updateEmployee();
    readEmployee(emp1, n_emplyee);
    printEmployee(emp1, n_emplyee);
#endif
    return 0;
}