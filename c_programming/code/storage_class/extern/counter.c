#include <stdio.h>
int counter=0;

int count()
{
    printf("CounterAddress: %p\n",&counter);
    counter++;
    return counter;
}
