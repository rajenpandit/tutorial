#include <map>
#include <string>
#include <iostream>

class Student
{
public:
    Student(const std::string& name, int age, int standard, int rollNo)
    {
        //assignment
        m_name = name;
        m_age = age;
        m_standard = standard;
        m_rollNo = rollNo;
    }

    const std::string& getName() const{
        return m_name;
    }
    int getAge() const {
        return m_age;
    }
    int getStandard() const{
        return m_standard;
    }
    int getRollNo() const{
        return m_rollNo;
    }
private:
    std::string m_name;
    int m_age;
    int m_standard;
    int m_rollNo;
};

class College{
public:
    void addStudent(const Student& student){
        if(m_studentMap.find(student.getStandard()) == m_studentMap.end())
            m_studentMap[student.getStandard()] = std::map<int, Student>();

        m_studentMap[student.getStandard()].emplace(student.getRollNo(), student);
    }
    const Student& getStudent(int standard, int rollNo) const{
        return m_studentMap.at(standard).at(rollNo);
    }
private:

    std::map<int, std::map<int,Student> > m_studentMap;     //std::map<standard, std::map<roll,Student>>
};

Student getStudent(){
    std::string name;
    int age;
    int standard;
    int rollNumber;
    std::cout << "Enter Name:";
    std::cin >> name;
    std::cout << "Enter Age";
    std::cin >> age;
    std::cout << "Enter Standard:";
    std::cin >> standard;
    std::cout << "Roll Number:";
    std::cin >> rollNumber;

    return Student(name, age, standard, rollNumber);
}

int main(){

    College collage;
    std::cout << "Add Students:" << std::endl;
    int should_continue;
    do{
        Student s = getStudent();
        collage.addStudent(s);
        std::cout << "Do you want to add more[y/n]:";
        std::cin >> should_continue;
    }while(should_continue == 1);

    int rollNo;
    int standard;
    std::cout << "Enter roll number and standard to get student:";
    std::cin >> rollNo;
    std::cin >> standard;
    Student s = collage.getStudent(standard, rollNo);
    std::cout << "Name:" << s.getName() << std::endl;
}