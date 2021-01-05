#ifndef __MIDDLE_SCHOOL_H_TUTORIAL__
#define __MIDDLE_SCHOOL_H_TUTORIAL__

#include "School.h"
#include <iostream>
class MiddleSchool : public SchoolBasic{
    public:
        // using SchoolBasic::admission;
        // using SchoolBasic::teachStudents;
        // using SchoolBasic::examsOfStudent;
        void admission(int cls, int numberOfStudents){
            if(cls == 1)
            {
                SchoolBasic::admission(numberOfStudents);
            }
            else if(cls > 1  && cls <=10)
            {
                nStudentsOfCls[ cls-2 ] += numberOfStudents;
                std::cout << "Admission taken for students  of class "<< cls << ", number of students:"
                    <<nStudentsOfCls[cls-2] << std::endl;
            }
        }
        void teachStudents(int cls)
        {
            if(cls > 1 && cls <= 10){
                std::cout << "Teaching students  of class "<< cls << ", number of students:"
                    <<nStudentsOfCls[cls-2] << std::endl;
            }
            else{
                SchoolBasic::teachStudents();
            }
        }
        void examsOfStudent(int cls){
            if(cls > 1 && cls <= 10){
                std::cout << "Teaching students  of class "<< cls << ", number of students:"
                    <<nStudentsOfCls[cls-2] << std::endl;
            }
            else{
                SchoolBasic::teachStudents();
            }
        }
    private:
        unsigned short nStudentsOfCls[9];
};


#endif