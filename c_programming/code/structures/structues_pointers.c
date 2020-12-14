#include <stdio.h>

struct Address
{
    char vill[20];
    char po[20];
    char dist[20];
    int pincode;
    char phone[13];
};

typedef struct Address Address;

struct StudentInfo
{
    char name[20];
    int rollNo;
    struct Address address;
};

typedef struct StudentInfo StudentInfo;


typedef struct EmplyeeInfo
{
    char name[20];
    int age;
    float salary;
    Address address;
} EmplyeeInfo;

void readAddress(Address* address)
{
    printf("Enter vill:");
    scanf("%s", address->vill);
    printf("Enter Po:");
    scanf("%s", address->po);
    printf("Enter Dist:");
    scanf("%s", address->dist);
    printf("Enter Pin Code:");
    scanf("%d", &address->pincode);
    printf("Enter Phone:");
    scanf("%s", address->phone);
}

void readStudentInfo(StudentInfo* studentInfo)
{
    printf("Enter Name:");
    scanf("%s",studentInfo->name);
    printf("Enter Roll Numnber:");
    scanf("%d", &studentInfo->rollNo);   // studentInfo->   ====   (*studentInfo).
    
    // scanf("%s", studentInfo->address.vill);
    readAddress( &studentInfo->address );
}

void displayAddress(Address* address)
{
    printf("Vill: %s\n", address->vill);
    printf("Po:%s\n", address->po);
    printf("Dist:%s\n", address->dist);
    printf("Pin Code:%d", address->pincode);
    printf("Phone:%s\n", address->phone);
}

void displayStudentInfo(StudentInfo* studentInfo)
{
    printf("Name:%s\n", studentInfo->name);
    printf("Roll Number:%d\n", studentInfo->rollNo);

    displayAddress(&studentInfo->address);
}
#define MAX_STUDENTS 10
int main()
{
    
    EmplyeeInfo em;
    readAddress(&em.address);  // this function will fill only address details.


    StudentInfo sInfo;
    readStudentInfo(&sInfo);  // this function will fill studentInfo details.
    displayStudentInfo(&sInfo);  // this function will display studentInfo details.


    StudentInfo students[MAX_STUDENTS];
    for(int i=0 ; i < MAX_STUDENTS; ++i)
    {
        printf("Enter Student Details for index : %d\n",i);
        readStudentInfo(&students[i]);
       // readStudentInfo(students+i);
       printf("------------------------------\n");
    }

    for(int i=0 ; i < MAX_STUDENTS; ++i)
    {
        displayStudentInfo(&students[i]);
        // displayStudentInfo(students + i);
        printf("------------------------------\n");
    }

}