#include<iostream>
class A
{
public:
    A(int x) : data(x)   // initialization list
    {
        // assignments 
        std::cout << "A(int)" << std::endl;
    }
    A(const A& obj) : data(obj.data)   // copy constructor
    {
        y = obj.y;
    }
    A(const A* obj) : data(obj->data)
    {
        y = obj->y;
    }
public:
    int getValueOfData(){
        return data;
    }
private:
    const int data;
    int y;
};

int main()
{
    int a = 5;
    A obj(a);
    A obj1 = obj;  // A obj1(obj);   // calls copy constructor
    A obj2 = &obj;
    // int x = 5;
    // int y = x;

    // obj.setData(5);
    std::cout << obj.getValueOfData() << std::endl;
    std::cout << obj1.getValueOfData() << std::endl;
    std::cout << obj2.getValueOfData() << std::endl;
}