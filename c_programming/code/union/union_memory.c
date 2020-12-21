#include <stdio.h>

typedef union  data_32
{
    char characters[4];
    int intData;
    float floatData;
}data_32;


int main()
{
    data_32 data;
    data.intData = 0;
    data.characters[0]='a';

  //  data.intData = 66;
    printf("characters[0] %c\n",data.characters[0]);
    printf("intData: %c\n", data.intData);
    printf("Size:%lu\n", sizeof(data_32));
}