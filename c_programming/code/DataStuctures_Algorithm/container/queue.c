#include <stdio.h>

#define ARRAY_SIZE 10
typedef struct Queue{
    int arr[ARRAY_SIZE];
    int back;
    int front;
} Queue;

int insert(Queue *que, int element)
{
    if(que->back < ARRAY_SIZE -1)
    {
        que->back++;
        que->arr[que->back] = element;
        return que->back;
    }
    else{
        return -1;
    }
}

int remove_element(Queue *que)
{
    int element = -1;
    if(que->front <= que->back)
    {
        element = que->arr[que->front];
        que->front++;
    }
    return element;
}

int main()
{
    Queue que;
    que.front = 0;
    que.back = -1;
    printf("Enter %d que elements \n", ARRAY_SIZE);
    for(int i=0; i<ARRAY_SIZE; ++i)
    {
        int element;
        scanf("%d",&element);
        insert(&que,element);
    }

    printf("Removing elements from queue:");
    for(int i=0; i<ARRAY_SIZE; ++i)
    {
        printf("Element:%d\n", remove_element(&que));
    }
}

