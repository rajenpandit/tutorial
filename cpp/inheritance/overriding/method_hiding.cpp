#include<iostream>

class A
{
public:
    void print(const char* str)
    {
        std::cout<<"A: "<< str << std::endl; 
    }
    void print(int data)
    {
        std::cout<<"A: "<< data << std::endl; 
    }
    void out(){
        std::cout<<"class A"<<"\n";
    }
};


class B : public A
{
public: 
    using A::print;  // will use print method from a if not overide in class B.
    void print(const char* str)   //overriding
    {
        std::cout<<"B: " << str << std::endl;
    }
    // void print(int data)
    // {
    //     A::print(data);
    // }
    void display()
    {
        std::cout << "class B"<<"\n";
    }
};

int main()
{
    B obj;
    obj.print("10");
    // obj.A::print(10);
    obj.print(10);
    obj.out();
    // obj.display();
}