#include<iostream>
class A
{
public:
    // A(){ 
    //     std::cout << "A()" << std::endl;
    // }
    A(int x) : data(x)   // initialization list
    {
        // assignments 
        std::cout << "A(int)" << std::endl;
    }
    // A(int x, float x1)
    // {
    //     std::cout << "A(int, float)" << std::endl;  
    // }
public:
    int getValueOfData(){
        return data;
    }
    // void setData(int x){
    //     data = x;
    // }
private:
    const int data;
};

int main()
{
    A obj(5);
    // obj.setData(5);
    std::cout << obj.getValueOfData() << std::endl;
}