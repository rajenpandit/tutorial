#include <stdio.h>

#define ARRAY_SIZE 10

typedef struct Stack{
    int arr[ARRAY_SIZE];
    int top;
} Stack;

int insert(Stack* sp, int element)  // push
{
    if(sp->top < (ARRAY_SIZE - 1))
    {
        sp->top = sp->top + 1;
        sp->arr[sp->top] = element;
        return sp->top;
    }
    else{
        return -1;
    }
}

int remove_element(Stack* sp)  // pop
{
    int element = -1;
    if(sp->top >= 0)
    {
        element = sp->arr[sp->top];
        sp->top = sp->top - 1;
    }
    return element;
}

int main()
{
    Stack stc;
    stc.top = -1;
    printf("Enter %d stack elements \n", ARRAY_SIZE);
    for(int i=0; i<ARRAY_SIZE; ++i)
    {
        int element;
        scanf("%d",&element);
        insert(&stc,element);
    }

    printf("Removing elements from stack:");
    for(int i=0; i<ARRAY_SIZE; ++i)
    {
        printf("Element:%d\n", remove_element(&stc));
    }
}