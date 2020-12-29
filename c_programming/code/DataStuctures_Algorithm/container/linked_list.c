#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char Name[20];
    unsigned short age;
    struct Node *next;
}Node;
// while(start != NULL)
// {
//     printf(start->name);
//     printf(start->age);
//     start = start->next;
// }
Node* createNode(Node* start)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    Node *lastNode = start;
    if(start == NULL)
    {
        return newNode;
    }
    while(lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    return newNode;
}

void addData(Node** start_p)
{
    Node* newNode = createNode(*start_p);
    if(*start_p == NULL)
    {
        *start_p = newNode;
    }
    printf("Enter name:");
    scanf("%s",newNode->Name);
    printf("Enter age:");
    scanf("%hd",&newNode->age);
    newNode->next = NULL;
}

void display(const Node* start)
{
    const Node* temp = start;
    printf("========================\n");
    while(temp != NULL)
    {
        printf("-------------------------\n");
        printf("Name: %s\n", temp->Name);
        printf("Age: %hd\n", temp->age);
        temp = temp->next;
    }
    printf("========================\n");
}

int x;
int *p = &x; // int*
int** p1 = &p;  //int**

int main()
{
    Node *start = NULL;

    while(1)
    {
        char ch;
        printf("Press 1 to add data, 2 to exit, 3 to print\n");
        scanf("\n%c",&ch);

        switch (ch)
        {
            case '1':
                addData(&start);
                break;
            case '2':
                break;
            case '3':
                display(start);
            default:
                printf("Enter a choice\n");
                break;
        };
        if(ch == '2')
            break;
    };
}