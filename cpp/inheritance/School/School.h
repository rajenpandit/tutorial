#ifndef __SCHOOL_H__TUTORIAL__
#define __SCHOOL_H__TUTORIAL__

class SchoolBasic{
public:
    SchoolBasic();
    void admission(int numberOfStudents);
    void teachStudents();
    void examsOfStudent();
private:
    unsigned short m_numberOfStudents;
};

#endif