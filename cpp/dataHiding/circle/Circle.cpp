#include "Circle.h"

Circle::Circle(float radius) : m_pi(3.14)
{
    m_radius = radius;
    m_area = m_pi * radius * radius;
    m_perimeter = 2 * m_pi * radius;
}

float Circle::area(){
    // return  m_pi * m_radius * m_radius;
    return m_area;
}

float Circle::perimeter(){
    return m_perimeter;
}