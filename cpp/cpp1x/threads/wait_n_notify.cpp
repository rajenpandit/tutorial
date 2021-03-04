#include <iostream>
#include <queue>
#include <thread>
#include <unistd.h>

std::queue<int> queue;
std::mutex m;
std::condition_variable cv;

bool isDataAvailable(){
    return !queue.empty();
}
void print(){
    while(true){
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk,isDataAvailable);
        int data = queue.front();
        queue.pop();
        std::cout <<"Thread[Print] Data: "<< data << std::endl;
    }
}

void read1(){
    while(true){
        int data;
        std::cout<<"Thread[Read1] Enter data:";
        std::cin >> data;
        queue.push(data);
        cv.notify_one();
    }
}

int main(){

    std::thread read_thread(&read1);
    std::thread print_thread(&print);
    read_thread.join();
    print_thread.join();
}