#include <iostream>

// Runtime polymorphism 
// 1. Inheritance
// 2. function Override  
// 3. Overridden function must be defined as virtual in base class.
// 4. Function call should be from a pointer.
class A
{
public:
    virtual void print(const char* data)
    {
        std::cout << "[A]: "<< data << std::endl; 
    }
};

class B : public A
{
public:
    void print(const char* data)
    {
        std::cout << "[B]: " << data << std::endl;
    }
};


int main(int argc , char ** argv)
{
    B obj;
    obj.print("Hello");
    A objA;
    A *ptr;
    if(argc == 1)
        ptr = &obj;
    else
        ptr = &objA;
    ptr->print("Test");   // run time polimorphism.
}
