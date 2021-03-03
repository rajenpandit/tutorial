#include <iostream>

typedef int (*function) (int,int);
class CallBack{
public:
    CallBack(function callback){
        m_callback = callback;
    }
    int execute(int a, int b){
        return m_callback(a,b);
    }
    int operator()(int a, int b){
        return m_callback(a,b);
    }
private:
    function m_callback;
};

int sum(int x, int y){
    return x+y;
}

int sub(int x, int y){
    return x-y;
}

int main(){
    CallBack sum_callback(&sub);
    int s=0;
    for(int i=0; i<10;  i++){
        s = sum_callback.execute(s,i);
    }
    std::cout << "Sum:" << s << std::endl;
}