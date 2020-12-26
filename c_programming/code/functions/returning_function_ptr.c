#include <stdio.h>

int sum(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}

void display(int a, int b)
{
    printf("%d %d", a, b);
}

typedef int (*func_p) (int, int);

func_p function_choice()
 {
    int choice;
    printf("Enter command type: \n1 -> Sum, \n2 -> Sub, \nother number for exit.\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
            return &sum;
        break;
    case 2: 
            return &sub;
    default:
        break;
    }
    return NULL;
 }
void assign_command( func_p *p)
{
    for(int i=0; i<5; ++i)
    {
        p[i]=function_choice();  // *(p+i)
    }
}

void execute_command(func_p *arr)
{
    for(int i=0; i<5; i++)
    {
        int a, b;
        printf("Enter two numbers:");
        scanf("%d%d",&a,&b);
        printf("Executed Value:%d\n",arr[i](a,b));
    }
}
int main()
{
    func_p arr[5];

    assign_command(arr);

    execute_command(arr);
}