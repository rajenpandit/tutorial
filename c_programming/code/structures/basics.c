#include <stdio.h>
#include <string.h>

#pragma pack(1)   //I will explain this later, this line is optional
struct Address
{
    char vill[20];
    char po[20];
    char dist[20];
    int pincode;
    char phone[13];
};

struct StudentInfo
{
    char name[20];
    int rollNo;
    struct Address address;
};

#define TOTAL_STUDENTS 1
int main()
{
    struct StudentInfo student1[TOTAL_STUDENTS];

    printf("address:%p\n",&student1);
    
    for(int i=0; i<TOTAL_STUDENTS; ++i)
    {
        printf("Enter Name:");
        scanf("%s",student1[i].name);
        printf("Enter Roll Number:");
        scanf("%d",&student1[i].rollNo);
        printf("Enter Vill:");
        scanf("%s",student1[i].address.vill);
        printf("Enter Pin Code:");
        scanf("%d",&student1[i].address.pincode);
    }

    printf("Students information:\n");

    for(int i=0; i<TOTAL_STUDENTS; ++i)
    {
        printf("Name:%s\n",student1[i].name);
        printf("Roll Num:%d\n",student1[i].rollNo);
        printf("Vill:%s\n",student1[i].address.vill);
        printf("PinCode:%d\n",student1[i].address.pincode);
        printf("------------------------------------\n");
    }

}
