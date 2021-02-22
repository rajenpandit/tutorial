#include <iostream>
#include <cstring>
class String{
public:
    String(char* data, size_t size)  // Constructor
    {
        m_ptr = new char[size+1];
        strncpy(m_ptr, data, size);
    }
    ~String()  // Destructor
    {
        std::cout << "Destructor called" << std::endl;
        delete[] m_ptr;
    }

    // void deleteMemory(){
    //     delete[] m_ptr;
    // }
    friend std::ostream& operator << (std::ostream& os, const String& str){
        os << str.m_ptr;
        return os;
    }
private:
    char* m_ptr;
};


void function(){
    char *ptr = new char[20];
    strcpy(ptr, "Hello");

    String str(ptr, strlen(ptr));
    // String* str1 = new String(ptr, strlen(ptr));
    // delete str1;
    std::cout << str << std::endl;

    delete[] ptr;

    char *ptr1 = new char[20];
    strcpy(ptr1, "World");
    // ... 
    delete[] ptr1;

    std::cout << str << std::endl;
    // str.deleteMemory();

    std::cout<<"About to delete str" << std::endl;
}

int main(){

    function();

}
