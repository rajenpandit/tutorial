#ifndef _CIRCLE_TUTORIAL_
#define _CIRCLE_TUTORIAL_

class Circle{
public:
    Circle(float radius);
private:
    const float m_pi;
    float m_area;
    float m_perimeter;
    float m_radius;
public:
    float area();
    float perimeter();
};

#endif