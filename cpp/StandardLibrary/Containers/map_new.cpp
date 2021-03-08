#include <map>
#include <sstream>
#include <iomanip>
#include <iostream>

class Employee{

public:
    enum Gender{
        Male,
        Female
    };
private:

    Employee(const std::string& emp_id, const std::string& emp_name){
        m_empId = emp_id;
        m_empName = emp_name;
    }
public:
    void setGender(Gender gender){
        m_gender = gender;
    }
    void setSalary(double salary){
        m_salary = salary;
    }
private:
    std::string m_empId;
    std::string m_empName;
    Gender m_gender;
    double m_salary;
    friend class Company;
};

class Company{
public:
    Company(){
        m_empId = 0;
    }
    std::string registerEmployee(const std::string& name){
        std::string emp_id = generateEmpId();
        Employee *emp = new Employee(emp_id, name);
        m_employees[emp_id] = emp;
        return emp_id;
    }
    Employee* getEmployee(const std::string& empId){
        return m_employees[empId];
    }
    ~Company(){
        for(auto p : m_employees){
            delete p.second;
        }
    }
private:
    std::string generateEmpId(){
        //emp_xxxx;
        std::stringstream ss;
        m_empId += 1;
        ss << "emp_" << std::setw(4) << std::setfill('0') << m_empId;
        return ss.str();
    }
private:
    std::map<std::string, Employee*> m_employees;
    int m_empId;
};

int main(){
    Company cmp;
    std::string empId = cmp.registerEmployee("Mohan");
    // cmp.getEmployee(empId)->setGender(Employee::Male);
    Employee* emp = cmp.getEmployee(empId);
    emp->setGender(Employee::Male);
}