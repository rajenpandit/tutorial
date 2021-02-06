#include <cstdio>
#include <cstring>
#include <iostream>
struct Person
{
private:
    char name[20];    // member variable
    int age;            // member variable
public:
    // void setName(Person* this, const char* name)
    virtual void setName(const char* name)   // member function
    {
        std::cout << "Name****: "<<name << std::endl;
        // strcpy(Person::name, name);
        std::cout << "Address in this:" << this << std::endl;
        strcpy(this->name, name);
    }
    void setAge(int age)
    {
        this->age = age;
    }
    const char* getName()
    {
        return name;
    }
    int getAge(){
        return age;
    }
};

typedef void (*setNamePtr) (Person* p, const char* name);

typedef void (Person::*setNamePtr1) (const char* name);

int main()
{
    Person p ;
#if 0
    long *vptr = (long*)&p;
    long *f = (long*) *vptr;
    setNamePtr ptr = (setNamePtr)*f;
    ptr(&p,"Hello");
    // (p.*ptr)("Ramesh");
#endif
    p.setName("Ram");
    p.setAge(20);
    std::cout<<"Address of p:" << &p <<"\n";
    // printf("Name:%s\n Age:%d\n",p.name,p.age);
    std::cout<<"Name:"<<p.getName() << " \nAge:" << p.getAge() << "\n";
    return 0;
    
}