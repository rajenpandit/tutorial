#include <stdio.h>

typedef struct Item
{
    const char name[20];
    float price;
}Item;

int main()
{
    const char str[20] = "Hello World";
    // str[2] = 'x';   //trying to update 2nd index of str which is  invalid because str is const.
    printf("%s\n",str);

    Item item = {"Hello", 20.0};
    // item.name[2] = 'x';  // this assignment is invalid since item.name is const.
    item.price = 40;
    printf("%s %f\n", item.name, item.price);

    const Item item1 = {"Hello", 20}; 
    // item1.name[2] = 'x'; 
    // item1.price = 40;   // both are invalid since Item is const;
    printf("%s %f\n", item1.name, item1.price);
}
