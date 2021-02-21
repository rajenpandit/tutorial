#include <string>
#include <iostream>  // istream , ostream

class String
{
public:

private:
    char m_name[50];
    friend std::istream & operator >> (std::istream& is, String & s)
    {
        is >> s.m_name;
        return is;
    }
    friend std::ostream & operator << (std::ostream& os, const String& s){
        os << s.m_name;
        return os;
    }
};

// std::istream & operator >> (std::istream& is, String & s)
// {
//     is >> s.m_name;
//     return is;
// }

int main()
{
    std::string name;
    String _name;
    std::cout << "Enter Name:";
    std::cin >> name;
    std::cin >> _name;  // cin.operator>> (_name);  // operator >> (cin, _name);
    std::cout << name;
    std::cout << _name;
    name = "xyz";
    name.assign("abc");
    // _name = "xyz";   // _name.operator=("xyz");
    // _name.assign("xyz");
    // _name.length();   // retruns lenght of the string.
    // _name.append("_abc");   // xyz_abc;
    // _name+="_abc"; // will append/concat _abc with existing string.
    // _name.compare("xyz_abc");  // return true/false if string is matched.
}