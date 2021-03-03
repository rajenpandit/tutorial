#include <thread>
#include <iostream>
#include <unistd.h>

void print(int i){
    while(true){
        std::cout << "print:" << i++ << std::endl;
        sleep(1);
    }
}

int main(){
    std::thread t1(&print,1);
    std::thread t2(&print,100);
    t1.join();
    t2.join();
    std::cout <<"Exiting Main:" << std::endl;
}