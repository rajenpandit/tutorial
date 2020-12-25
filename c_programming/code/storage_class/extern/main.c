#include <stdio.h>
#include "counter.h"

void reset()
{
    counter =0;
}
int main()
{
    int i;
    for( i=0; i<10; i++)
    {
        printf("Count :%d\n", count());
    }
    printf("-----------------------\n");
    printf("Address of counter[main]%p\n",&counter);
    reset();
    for( i=0; i<10; i++)
    {
        printf("Count :%d\n", count());
    }
}