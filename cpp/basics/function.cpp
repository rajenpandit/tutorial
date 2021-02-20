#include <iostream>
class Calculator
{
public:
    double sum(int a, int b=0, int c=0, int d=0){
        return a+b+c+d;
    }

    // double area(int a, int b){
    //     return 2* (a+b);
    // }
};


int main(){
    Calculator c;
    std::cout << "Area:" << c.sum(5) << "|" << c.sum(5,6) << "|" 
        << c.sum(3,4,6)<< std::endl;
}