#ifndef __COLLEGE_H_TUTORIAL__
#define __COLLEGE_H_TUTORIAL__

#include <string>

class Student;

class College
{
public:
    College(Student* student) : m_student(student){

    }
    const std::string& getStudentName();
private:
    Student* m_student;
};

#endif