#include <memory>
#include <iostream>
#include <queue>

class Printer{
public:
    Printer(){
        m_data = "default";
        std::cout << "Constructor called: Printer()" << std::endl;
    }
    Printer(const std::string& data){
        std::cout << "Constructor called: Printer(const std::string& data)" << std::endl;
        m_data = data;
    }
    Printer(const Printer& printer){
        std::cout << "Copy constructor called" << std::endl;
        m_data = printer.m_data;
    }
    ~Printer(){
        std::cout << "Destructor called" << std::endl;
    }
    void print(){
        std::cout << m_data << std::endl;
    }
    static void queue(std::shared_ptr<Printer> obj){
        s_printQue.push(obj);
    }
    static void execute(){
        while(!s_printQue.empty()){
            s_printQue.front()->print();
            s_printQue.pop();
        }
    }
private:
    std::string m_data;
private:
    static std::queue<std::shared_ptr<Printer>> s_printQue;
};

std::queue<std::shared_ptr<Printer>> Printer::s_printQue;

void print(const std::string& data){
    std::shared_ptr<Printer> p(new Printer(data));
    Printer::queue(p);
}

int main(){
    print("Print 1");
    print("Print 2");
    Printer::execute();
}