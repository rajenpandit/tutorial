#include <stdio.h>
struct Address
{
    char vill[20];
    char po[20];
    char dist[20];
    int pincode;
    char phone[13];
};

typedef struct Address Address;  // typedef can be used like this or below format.

typedef struct StudentInfo
{
    char name[20];
    int rollNo;
    Address address;
} StudentInfo;

/*
typedef unsigned int PIN_CODE;
typedef char PHONE_NUMBER[14];
typedef int SALARY; */

int main()
{
    StudentInfo students;  //Since StudentInfor is typedef, struct keyword is not required anymore
}