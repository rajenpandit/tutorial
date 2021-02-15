#include <iostream>

// Uniary Operator: That operates with one operand
//  Ex: -2 (Operand is 2 and operator - ).
//  Ex: *p  
// Binary Operator: That operates with two operand 
//  Ex: 1 + 2 (Operands are 1 and 2, Operator + )
//  Ex: 1 - 2 (Operands are 1 and 2, Operator - )
// Tertiary Operator: That operates with Three operands
//  Ex: (a==b) ? a : c [ condition ? true : false ] (Operands condition, true, false, Operator :?)

class A
{
public:
    A(int x , int y){
        this->x=x;
        this->y=y;
    }
public:
    A operator+( A& obj)
    {
        int x1 = x + obj.x;
        int y1 = y + obj.y;
        A a( x1, y1 );
        return a;
    }

    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
private:
    int x;
    int y;
    char c;
};

int main(){
    int a = 10;
    int b = 20;
    int d = 5;
    int c = a + b + d;
     
    A obj1(10,20);
    A obj2(60,40);

    A obj3 = obj1 + obj2;
    // A obj3 = obj1.operator+(obj2);
    std::cout << "X:" << obj3.getX() << " Y:"<< obj3.getY() << std::endl;

    return 0;
}