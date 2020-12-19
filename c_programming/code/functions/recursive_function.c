#include <stdio.h>
#include <stdlib.h>

void recursive_function(int a)
{
    int* x = malloc(sizeof(int)*a);
    if (a < 20)
        recursive_function(a+1);
    printf("x[%p] %p, a[%p] %d\n", &x, x, &a, a);
    printf("Exiting function\n");
    return;
}

int main()
{
    const char *p = "Hello World\n";
    printf("p[%p]%p",&p,p); 
    recursive_function(10);
}