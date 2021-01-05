#include "HighSchool.h"

int main()
{
    HighSchool school;
    school.SchoolBasic::admission(10);
    school.admission(2,5);
    school.SchoolBasic::teachStudents();
    school.teachStudents(2);
    school.SchoolBasic::admission(5);
    school.SchoolBasic::teachStudents();
}