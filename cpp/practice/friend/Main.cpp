#include <iostream>
#include "Student.h"
#include "College.h"

int main()
{
    std::string str;
    std::cout<<"Enter Name:";
    std::cin >> str;
    // Student* student = (Student*)malloc(sizeof(Student));  // doesn't call constructor
    Student* student = new Student(str,20);
    College college(student);
    std::cout << college.getStudentName() << std::endl;
}