#include <stdio.h>

int count();
extern int counter;
void reset()
{
    counter =0;
}
int main()
{
    for(int i=0; i<10; i++)
    {
        printf("Count :%d\n", count());
    }
    printf("-----------------------\n");
    printf("Address of counter[main]%p\n",&counter);
    reset();
    for(int i=0; i<10; i++)
    {
        printf("Count :%d\n", count());
    }
}