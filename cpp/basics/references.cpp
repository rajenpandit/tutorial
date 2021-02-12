#include <iostream>
class A
{
public:
    void swap_using_pointer(int *a, int* b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void swap_using_reference(int& a, int& b)  //alias
    {
        int temp = a;
        a = b;
        b = temp;
    }
};

int main()
{
    A obj;
    int x = 10;
    int &b = x;  // b refers to x. Or, b is an alias of x.
    // int &c;    // this is invalid.
    int y = 20;
    obj.swap_using_pointer(&x, &y);
    std::cout << "x:" << x << " y:"<< y << std::endl;
    obj.swap_using_reference(x, y);

    std::cout << "x:" << x << " y:"<< y << std::endl;
}