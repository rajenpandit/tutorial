#include  "Shape.h"
class Circle : public Shape{
public:
    Circle(float radius){
        m_area = 3.14 * radius * radius;
        m_perimeter = 2 * 3.14 * radius;
    }
    float area(){
        return m_area;
    }
    float parimeter(){
        return m_perimeter;
    }
};