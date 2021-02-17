#include <iostream>
#include <string>

// class String{
// public:
//     String(){}
//     String(const char* name){
//         strcpy(m_name, name);
//     }
    //    void operator=(const char* name){
    //        strcpy(m_name, name);
    //    }
// private:
//     char m_name[100];
// }

// int main()
// {
//     String name;
//     name = "Ram";  // name.operator=("Ram");
// }

class Student;
class College
{
public:
    College(const Student& student) : m_student(student)
    {
        // m_student = student;   // m_student.operator=(student);
    }
    const std::string& getStudentName();

    void xyz();
private:
    const Student& m_student;
};

class Student{
public:
    enum Gender{
        Male,
        Female
    };
public:
    Student(){
    }

    Student(const std::string& name, int age, Gender gender){
        m_name = name;
        m_age = age;
        m_gender = gender;
    }
    void operator=(const Student& student){
        m_name = student.m_name;
        m_age = student.m_age;
        m_gender = student.m_gender;
    }

private:
    std::string m_name;
    int m_age;
    Gender m_gender;

    // friend class College;  // friend class
    friend const std::string& College::getStudentName();  // friend function
};


const std::string& College::getStudentName()
{   
    return m_student.m_name;
}
void College::xyz(){
    // std::cout << m_student.m_name << std::endl; // cannot access
}


int main()
{
    Student s("Ram", 20, Student::Male);
    College c(s);

    // std::cout << "Name:" << s.getName() << std::endl;
    std::cout << "Name:" << c.getStudentName() << std::endl;

}