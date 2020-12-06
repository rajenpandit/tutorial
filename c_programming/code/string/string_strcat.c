#include <stdio.h>
#include <string.h>

void string_concat(char *dst, char* src)
{
    while(*dst != '\0')
    {
        dst++;
    }
    strcpy(dst,src);
}
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
    strcat(fullName, " ");
    strcat(fullName, lastName);
    printf("Full Name: %s\n", fullName);

}