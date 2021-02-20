#ifndef __STUDENT_H__TUTORIAL
#define __STUDENT_H__TUTORIAL
#include <string>
#include <iostream> 
#include "College.h"
class Student
{
public:
    Student(const std::string& name, int age){
        m_name = name;
        m_age = age;
    }
private:
    const std::string& getName(){
        return m_name;
    }
private:
    std::string m_name;
    int m_age;
    // friend class College;
    friend const std::string& College::getStudentName();
};

#endif