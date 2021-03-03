#include <iostream>
#include <queue>
#include <thread>
#include <unistd.h>

std::queue<int> queue;
void print(){
    while(true){
        if(!queue.empty()){
            int data = queue.front();
            queue.pop();
            std::cout <<"Data: "<< data << std::endl;
        }
        else{
            std::cout <<"Waiting for a second"<< std::endl;
            sleep(1);
        }
    }
}

void read1(){
    while(true){
        for(int i=0; i<50; ++i)
            queue.push(i); 
        sleep(1);
    }
}

int main(){

    std::thread read_thread(&read1);
    std::thread print_thread(&print);
    read_thread.join();
    print_thread.join();
}