#include <stdio.h>

int main()
{
    int x = 50;
    int y = -50;
    printf("Value in Decimal=> \t\t\t\t x:%d \t y:%d\n", x,y);
    printf("Value in Decimal (unsigned)=>\t x:%u \t y:%u\n",x,y); // y's value can be calculated using two's complement
    printf("Value in Ascii character=>\t\t %c \t\t %c\n",x,y);
    printf("Value in hexadecimal=>\t\t\t %x \t %x\n",x,y);
    printf("Value in hexadecimal(0x)=>\t\t %p \t %p \n",x,y);

    // placement formatter
    int salary = 1000;
    int hra = 100;
    int bonus = 10;
    /*
     %[formatter][y]d, there will be y placess alined from right
    */ 
    printf("Salary:\t\t%4d\n",salary);  
    printf("HRA:\t\t%04d\n",hra);
    printf("Bonus:\t\t%04d\n",bonus);
    printf("----------------------------\n");
    printf("Total:\t\t%d\n\n\n",salary + hra + bonus);


    // placement formatter
    float salary_f = 1000;
    float hra_f = 100;
    float bonus_f = 10;
    /*
     %[formatter][y]f, there will be y placess alined from right
    */ 
    printf("Salary:\t\t%7.2f\n",salary_f);  
    printf("HRA:\t\t%7.2f\n",hra_f);
    printf("Bonus:\t\t%07.2f\n",bonus_f);
    printf("----------------------------\n");
    printf("Total:\t\t%7.2f\n",salary_f + hra_f + bonus_f);


    return 0;
}