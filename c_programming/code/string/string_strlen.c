#include <stdio.h>
#include <string.h>
// int str_length(char *p)
// {
//     int length=0;
//     while(*p != '\0')
//     {
//         length++;
//     }
//     return length;
// }
int main()
{
    char str[50];  //index  0 to 49
    printf("Enter a string:\n");
    scanf("%s",str);
    int length= strlen(str);

    printf("length:%d\n",length);
    // print in reverse order
    for(int i=length-1; i>=0; --i)
    {
        printf("%c",str[i]);
    }
}