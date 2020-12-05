#include <stdio.h>
#include <string.h>

void str_copy(char *dst, char* src)
{
    while(*src != '\0')
    {
        *dst = *src;
        src++;
        dst++;
    }
    *dst='\0';
}

int main()
{
    char str[50];
    char strCopy[50];
    printf("Enter  a string:");
    scanf("%s",str);
    // str_copy(strCopy,str);
    strcpy(strCopy, str);
    printf("Copied string:%s\n",strCopy);
}