#include <stdio.h>
int main()
{
    char str[12];
    scanf("%s",str); //Hello_World
    for(int i=sizeof(str)-1 ; i >= 0; --i)
    {
        printf("%c",str[i]);
    }
    return  0;
}