#include <stdio.h>

float calculateSellingPrice(float cost, const float* p, float* p1)
{
    float sellingPrice = cost + (cost * (*p)/100);
    *p1 = sellingPrice;  // if by mistake we do *p = sellingPrice then compiler will give error
    return sellingPrice;
}

int main()
{
    const float profit_margin = 5.0;  // intialization is possible but assignment is not.
    float sellingPrice = 0;  // initialization
    //sellingPrice = 0;  // assignment
    printf("%4.2f\n",calculateSellingPrice(100, &profit_margin, &sellingPrice));
    printf("%4.2f\n",calculateSellingPrice(150, &profit_margin, &sellingPrice));
    return 0;
}