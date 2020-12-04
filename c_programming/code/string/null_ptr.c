#include  <stdio.h>

void printArray(char* p)
{
    while(*p != '\0')  // checks for null pointer
    {
        printf("%p:%c\n",p, *p);
        p++;
    }
}

int main()
{
    char str[] = "Hello World";
    printArray(str);
    return 0;
}