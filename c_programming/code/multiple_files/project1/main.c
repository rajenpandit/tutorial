#include <stdio.h>
#include "arithmetic_operation.h"
#include "add_n_numbers.h"


int main()
{
    int a, b;
    printf("Enter two number:\n");
    scanf("%d%d",&a, &b);
    printf("Sum of two numbers:%d\n", sum(a,b));
    printf("Sum of %d to %d: %d", a, b, addNNumbers(a,b));
}