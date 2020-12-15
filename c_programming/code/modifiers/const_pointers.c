#include<stdio.h>

int main()
{
    int x = 10;
    int y = 30;

    const int* p_int;    
 // int const * p_int;  // also can be written like this.
    p_int = &x;
    //*p_int = 20;  // This assignment is invalid because *p_int is constant.
    p_int = &y;     // This assignment is valid since p_int is not constant.

    int* const p1_int = &x;
    // p1_int = &y;   // This assignment is invalid since p1_int is constant.
    *p1_int = 20;


    const int* const p2_int = &x;
    // p2_int = &y;   // This assignment is invalid since p2_int is constant. 
    // *p2_int = 20;  // This assignement is invalid since *p2_int is  constant.

    printf("x:%d\n", x);
    printf("%d\n",*p_int);

}