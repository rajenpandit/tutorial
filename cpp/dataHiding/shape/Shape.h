#ifndef _SHAPE_TUTORIAL_
#define _SHAPE_TUTORIAL_

class Shape{
public:
    virtual float area() = 0 ;
    virtual float parimeter() = 0;
protected:
    float m_area;
    float m_perimeter;
};

#endif