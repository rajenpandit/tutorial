#include <stdio.h>


int main()
{
    register int x = 5;

    //printf("address of x : %p\n", &x);  // invalid:  register variable doesn't have address.
    printf("x:%d\n",x);

}