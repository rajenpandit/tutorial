#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/**
 *  Select one element from array and find smaller value from rest of the array elements.
 *  Swap smaller value with the current.
 *  Repeat the process.
 */
void sort(int* const ptr, const int size)
{
    int* pos = ptr;
    int* min;
    int* max;
    int* end_ptr = ptr + size;
    while(pos < end_ptr-1)
    {
        min=pos;
        max=pos+1;
        while(max < end_ptr)
        {
            if(*max < *min)
            {
                min = max;
            }
            max++;
        }
        swap(pos, min);
        pos++;
    }
}
void display(int *p, const int size)
{
    for(int i=0; i<size; ++i)
    {
        printf("%d ", p[i]);  // *(p+i)
    }
    printf("\n");
}
int main()
{
    int arr[]={4,6,2,3,8,9,0,27,45,5};
    const int numberOfElements = sizeof(arr)/sizeof(int);
    sort(arr, numberOfElements);
    display(arr, numberOfElements);
}