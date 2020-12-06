#include <stdio.h>
#include <string.h>

int string_compare(char* p1, char* p2)
{
    while( (*p1 == *p2)  && *p1 != '\0' && *p2 != '\0')
    {
        p1++;
        p2++;
    }
    if(*p1 ==  '\0' && *p2 == '\0')
    {
        return 0;
    }
    else
    {
        return *p1 - *p2;
    }
    
}
int main()
{
    char name1[20];
    char name2[20];

    printf("Enter name1 and name2:");
    scanf("%s",name1);
    scanf("%s",name2);
    // int retVal = string_compare(name1, name2) ;
    int retVal = strcmp(name1, name2) ;
    if(retVal == 0)
    {
        printf("name1 and name2 are equal\n");
    }
    else  if(retVal > 0)
    {
        printf("name1 is greater than name2\n");
    }
    else{
        printf("name1 is lesser than name2\n");
    }
}