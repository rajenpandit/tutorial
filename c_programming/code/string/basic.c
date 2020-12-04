
#include  <stdio.h>
int main()
{
    char str[] = "Hello World";
    printf("Sizeof str:%ld\n",sizeof(str));
    for(int i=0; i<sizeof(str); ++i)
    {
        printf("%p:%c\n",&str[i], str[i]);
    }
    return 0;
}