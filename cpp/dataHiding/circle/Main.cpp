#include "Circle.h"
#include <iostream>

int main(){
    Circle c1(5);
    //c1.m_area = 100; // m_area is not accesible because it is private member of Circle.
    std::cout<<"Radius:"<<c1.area()<<std::endl;
    std::cout<<"Radius:"<<c1.area()<<std::endl;
    std::cout<<"Radius:"<<c1.area()<<std::endl;
    std::cout<<"Radius:"<<c1.area()<<std::endl;
}