#include <iostream>
class A
{
public:
    void print(){
        std::cout << "Inside class A" << std::endl;
    }

    void out()
    {
        std::cout << "Out inside A:" << std::endl;
    }
// private:
//     int a;
};


class B
{
public:
    void display()
    {
        std::cout << "Inside class B" << std::endl;
    }
public:
    void out()
    {
        std::cout << "Out inside B:" << std::endl;
    }
};

class C :public A, public B
{
// public:

};

int main()
{
    C obj;
    obj.print();
    obj.display();
    // obj.out(); // multiple function found in base class.
    obj.A::out();
    obj.B::out();
    return 1;
}