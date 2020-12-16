#include <stdio.h>

typedef struct Item
{
    char name[20];
    float price;
}Item;

void readItemData(Item *item)
{
    printf("Enter Item Name:\n");
    scanf("%s",item->name);
    printf("Enter Price:");
    scanf("%f",&item->price);
}

void displayItemData(const Item *item)
{
    printf("Item Name:%s\n", item->name);
    printf("Item Price:%f\n", item->price);
}

int main()
{
    Item item;
    readItemData(&item);
    displayItemData(&item);
}