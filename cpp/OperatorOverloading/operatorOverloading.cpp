#include <iostream>
#include "Data1.h"

class Data
{
public:
    Data(int data){
        m_data = data;
    }

    int operator+(Data& d1)
    {
        return m_data + d1.m_data;
    }
    // int operator-(Data& d1)
    // {
    //     std::cout << "Data::Operator -" << std::endl;
    //     return m_data - d1.m_data;
    // }

    int operator-(Data1& d1)
    {
        return m_data - d1.m_data;
    }
public:
    int m_data;
};

int operator-(Data& d1, Data& d2)
{
    std::cout << "Operator -" << std::endl;
    return d1.m_data - d2.m_data;
}



int operator-(Data1& d1, Data& d2){
    return d1.m_data - d2.m_data;
}

int main(){
    Data d1(10);
    Data d2(20);
    Data1 data1(50);
    int x = d1 + d2;  // d1.operator+(d2);
    int y = d2 - d1;  // operator-(d2, d1);
    int a = d1 - data1;  // d1.operator-(data1);
    int b  = data1 - d1;  // data1.operator-(d1);  // operator-(data1, d1)

    std::cout << "x:" << x <<"\ny:" << y << std::endl;
    std::cout << "a:" << a << "b:" << b << std::endl;
}