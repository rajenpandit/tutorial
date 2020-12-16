#include <stdio.h>

int main()
{
    int x;
    printf("Enter a value:");
    scanf("%d",&x);
    const int y = x;
    printf("y:%d",y);
}