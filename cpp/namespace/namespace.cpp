#include<iostream>

// using namespace std;

namespace my_namespace1
{
    class string{
    public:
        string(){
            std::cout << "my_namespace1::string" << std::endl;
        }
    private:
        char m_str[100];
    };

    void print(){
        std::cout << "my_namespace1::print" << std::endl;
    }
}

namespace my_namespace2
{
    class string{
    public:
        string(){
            std::cout << "my_namespace2::string" << std::endl;
        }
    private:
        char m_str[100];
    };
    namespace file{
        void print(){
            std::cout << "my_namespace2::file::print" << std::endl;
        }
    }
    namespace terminal{
        void print(){
            std::cout << "my_namespace2::terminal::print" << std::endl;
        }
    }
}

// using namespace my_namespace1;
// using namespace my_namespace2;
// using namespace my_namespace2::file;
int main()
{
    my_namespace2::string s;
    my_namespace1::print();
    my_namespace2::file::print();
    my_namespace2::terminal::print();
}