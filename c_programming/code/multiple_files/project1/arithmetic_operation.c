#include "arithmetic_operation.h"


int sub(int a, int b)
{
    return  a-b;
}

int mul(int a, int b)
{
    return a*b;
}

int div(int a, int b)
{
    if(b!=0)
        return a/b;
    return -1;
}