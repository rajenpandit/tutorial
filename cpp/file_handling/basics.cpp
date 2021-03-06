#include <fstream>
#include <iostream>

int main(){
    std::fstream fs("test.txt", 
        std::ios_base::in |
         std::ios_base::out | 
         std::ios_base::app);
    if(!fs.is_open()){
        std::cerr << "Cannot open file" << std::endl;
    }
    fs << "Hello" << std::endl;
    std::cout<<fs.tellp()<<std::endl;
    fs.seekp(3);
    std::cout<<fs.tellp()<<std::endl;
    std::string str;
    fs >> str;
    std::cout << "Read:" << str << std::endl;
    return 1;
}