#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

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

int main(){
    #if 0
    int choice;
    printf("1. Add new\n 2. Modify\n 3. Delete\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        /* code */
        break;
    case 2:
        break;
    case 3: 
        break;
    default:
        break;
    #endif

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
    return 0;
}