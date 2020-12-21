#include <stdio.h>
#pragma pack(1)
typedef struct Address
{
    char vill[20];
    char po[20];
    int  pin;
} Address;
typedef struct StudentInfo
{
    char name[20];
    int rollNo;
    char class[20];
    Address address;
}StudentInfo;

typedef struct EmployeeInfo
{
    char name[20];
    double salary;
    Address address;
}EmployeeInfo;


typedef struct Person1
{
    StudentInfo student;
    EmployeeInfo employee;
}Person1;

typedef union Person2
{
    StudentInfo student;
    EmployeeInfo employee;
}Person2;

int main()
{
    printf("Size of Person:%lu\n", sizeof(Person1));  //160
    printf("Size of Person:%lu\n", sizeof(Person2));  //88
}