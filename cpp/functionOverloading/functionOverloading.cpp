#include <iostream>
class Shape{
public:
    float area(float radius){
        std::cout<<"Calculating area using float overload"<<std::endl;
        return pi * radius * radius;
    }
    float area(int radius){
        std::cout<<"Calculating area using int overload"<<std::endl;
        return pi * radius * radius;
    }
    float area(const char *radius){
        std::cout<<"Calculating area using char* overload"<<std::endl;
        float r = atof(radius);
        return pi * r * r;
    }
    float perimeter(float radius){
        return 2 * pi * radius;
    }
    float area(float l, float b){
        return l * b; 
    }
    float perimeter(float l, float b){
        return 2 * (l+b);
    }
private:
    const float pi = 3.14; 
};

int main(){
    Shape s;
    float f_radius = 9.0;
    int i_radius = 9;
    const char * r = "9";
    std::cout<<"Area of Circle:"<<s.area(f_radius)<<std::endl;
    std::cout<<"Area of Circle:"<<s.area(i_radius)<<std::endl;
    std::cout<<"Area of Circle:"<<s.area(r)<<std::endl;
    std::cout<<"Perimeter of Circle:"<<s.perimeter(10.0)<<std::endl;
    std::cout<<"Area of Ractangle:"<<s.area(10.0, 15.0)<<std::endl;
    std::cout<<"Perimeter of Ractangle:"<<s.perimeter(10.0, 15.0)<<std::endl;
}