#include <stdio.h>
#include <string.h>
int main()
{
    char firstName[20];
    char lastName[20];
    char fullName[50];

    printf("Enter First Name:");
    scanf("%s",firstName);
    printf("Enter Last Name:");
    scanf("%s",lastName);

    strcpy(fullName, firstName);
    fullName[strlen(firstName)] = ' ';
    //*(fullName + strlen(firstName)) = ' ';
    //strcpy(fullName + strlen(firstName)," ");
    strcpy(fullName + strlen(firstName)+1, lastName);
    printf("Full Name: %s\n", fullName);

}