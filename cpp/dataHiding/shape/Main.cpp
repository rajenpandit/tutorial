#include <iostream>
#include "Circle.cpp"
int main(){
    Circle c1(5.0);
    // c1.m_area = 100;
    std::cout<<"area:"<<c1.area()<<std::endl;
}