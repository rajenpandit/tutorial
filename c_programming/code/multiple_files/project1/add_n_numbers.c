#include "add_n_numbers.h"
int addNNumbers(int start, int end)
{
    int s = 0;
    int n = start;
    while(n <= end)
    {
        s = sum(s,n);
        n++;
    }
    return  s;
}