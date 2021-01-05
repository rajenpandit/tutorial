#include "School.h"
#include <iostream>

SchoolBasic::SchoolBasic() 
{
    m_numberOfStudents = 0;
}
void SchoolBasic::admission(int numberOfStudents){
    m_numberOfStudents += numberOfStudents;
    std::cout << "Admission taken for " << m_numberOfStudents << " students of class1"<< std::endl;
}
void SchoolBasic::teachStudents()
{
    std::cout << "Teaching "<< m_numberOfStudents << " students"<<std::endl;
}
void SchoolBasic::examsOfStudent()
{
    std::cout << "Conducting exams for "<< m_numberOfStudents << " students"<<std::endl;
}