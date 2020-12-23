#include <stdio.h>



int counter()
{
    static int x = 0;    // static keyword tells compiler not to destruct memomory while returnning from function.
    printf("Address of x:%p\n", &x);
    x++;
    return x;
}

int main()
{
    printf("Counter:%d\n", counter());
    printf("Counter:%d\n", counter());

}