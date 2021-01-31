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

int writeEmployee(const Employee* emp, size_t n_employee)
{
    FILE* fp = fopen(EMPLOYEE_FILE, "wb");
    if(fp == NULL)
        return -1;
    int i;
    for( i=0; i<n_employee; ++i )
    {
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

void addEmployee(){
    int index;
    printf("Enter index:");
    scanf("%d",&index);

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
    return 0;
}