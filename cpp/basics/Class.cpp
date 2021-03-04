#include <iostream>
class A{
public:
    void setData(int data){
        m_data = data;
    }
    int getData() const{
        return m_data;
    }
    static void setStaticData(int data){
        m_staticData = data;
    }
    static int getStaticData(){
        return m_staticData;
    }
private:
    int m_data;
    static int m_staticData;
};

int A::m_staticData = 0;


class Area{
public:
    static float circle(float radius){
        return m_pi * radius * radius;
    }
    static float ractangle(float l, float b){
        return l*b;
    }
private:
    static float m_pi;
};

float Area::m_pi = 3.14;

// float pi = 3.14;

// float circle(float radius){
//     return pi * radius * radius;
// }

// int sum(int x, int y){
//     return pi + x + y;
// }

int main(){
    A obj;
    A obj2;
    obj.setData(5);
    obj2.setData(20);
    A::setStaticData(30);
    std::cout << "static Data:" << A::getStaticData() << "|" << A::getStaticData() << std::endl;
    std::cout << obj.getData() << "|" << obj2.getData()<< std::endl;
}