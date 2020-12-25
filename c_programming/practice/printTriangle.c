#include <stdio.h>

int main()
{
    const int n=5;
    int x=1;
    for(int i=1; i<=n; ++i)
    {
        for(int s=1; s<=n-i; ++s)
        {
            printf(" ");
        }
        for(int j=1; j<=i; ++j)
        {
            printf("* ");
        }
        printf("\n");
    }
}