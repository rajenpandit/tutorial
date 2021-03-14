
#include <iostream>
class Test{
public:
    Test(){
        std::cout<<"Constructor Called"<<std::endl;
    }
    ~Test(){
        std::cout<<"Destructor Called"<<std::endl;
    }
    void print(){
        std::cout << "Test print" << std::endl;
    }
};
template<class PtrType>
class SharedPointer{
public:
    SharedPointer(){
        m_ptr = nullptr;
        m_count_p = nullptr;
    }
    SharedPointer(PtrType* ptr) : m_ptr(ptr){
        m_count_p = new int(1);
    }
    SharedPointer(const SharedPointer& ptr){
        m_ptr = ptr.m_ptr;
        m_count_p = ptr.m_count_p;
        (*m_count_p)++;
    }
    void operator=(const SharedPointer& ptr){
        if(m_count_p != nullptr){
            (*m_count_p)--;
            if(*m_count_p == 0)
                delete m_ptr;
        }
        m_ptr = ptr.m_ptr;
        m_count_p = ptr.m_count_p;
        (*m_count_p)++;
    }
    int getCount(){
        if(m_count_p)
            return *m_count_p;
        return 0;
    }
    
    ~SharedPointer(){
        if(m_count_p!=nullptr){
            (*m_count_p)--;
            if(*m_count_p == 0)
                delete m_ptr;
        }
    }
    PtrType* get(){
        return m_ptr;
    }
    PtrType* operator->(){
        return m_ptr;
    }
private:
    PtrType* m_ptr;
    int* m_count_p;
};


int main(){
    SharedPointer<Test> sp;
    {
        SharedPointer<Test>  p(new Test());
        std::cout << p.getCount() << std::endl;
        {
            SharedPointer<Test>  p1 = p;  // SharePointer p1(p)
            std::cout << p.getCount() << std::endl;
        }
        std::cout << p.getCount() << std::endl;
        sp = p;
        std::cout << p.getCount() << std::endl;
        // SharedPointer test(new Test());
        // SharedPointer p2 = test;
        // p2 = p;   // p2.operator=(p)
        // std::cout<<"p is  going out of scope" << std::endl;
    }
    // sp.get()->print();
    sp->print();  // sp.operator ->()
    std::cout << sp.getCount() << std::endl;
}