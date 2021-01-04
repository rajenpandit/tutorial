#include <iostream>
class Circle{
public:
    Circle(float radius){
        m_area = m_pi * radius * radius;
        m_perimeter = 2 * m_pi * radius;
    }
    const float m_pi = 3.14;
    float m_area;
    float m_perimeter;

    float area(){
        // return  m_pi * m_radius * m_radius;
        return m_area;
    }

    float perimeter(){
        return m_perimeter;
    }
};


int main(){
    Circle c1(5);
    std::cout<<"Radius:"<<c1.area()<<std::endl;
    std::cout<<"Radius:"<<c1.area()<<std::endl;
    std::cout<<"Radius:"<<c1.area()<<std::endl;
    std::cout<<"Radius:"<<c1.area()<<std::endl;
}