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


class B : public A
{
public:
    void display()
    {
        std::cout << "Inside class B" << std::endl;
    }
private:
    void out()
    {
        std::cout << "Out inside B:" << std::endl;
    }
};

class C :  public B
{
// public:

};

int main()
{
    C obj;
    obj.print();
    obj.display();
    // obj.out(); // throws error since out is private in B;
    obj.A::out();  // out of A will be called
    return 1;
}