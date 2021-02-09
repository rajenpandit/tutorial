#include<iostream>

class A
{
public:
    void print(const char* str)
    {
        std::cout<<"A: "<< str << std::endl; 
    }
    void out(){
        std::cout<<"class A"<<"\n";
    }
    int getPercentage(){
        return 10;
    }
};


class B : public A
{
public: 
    void print(const char* str)   //overriding
    {
        std::cout<<"B: " << str << std::endl;
    }
    void display()
    {
        std::cout << "class B"<<"\n";
    }
    int getPercentage(){
        return A::getPercentage() + 5;
    }
};

int main()
{
    B obj;
    obj.print("Test");
    obj.out();
    // obj.display();
    std::cout << obj.getPercentage();
}