#include  <stdio.h>

int main()
{
    char str[] = "Hello World";
    printf("%s\n",str);  // printf can be used to print string
    printf("%s  - %s  - %d \n",str, "Test String", 123); // it can be used  with other formattor  like %d
    
    char name[50];
    int  salary;
    scanf("%s",name);  //note uses of '&' with %s and %d
    scanf("%d",&salary);

    printf("%s : %d",name,salary);
    return 0;
}