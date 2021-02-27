#include <iostream>
#include <map>
#include <string>
#include <vector>

int main(){
// uses of auto keyword

    int x = 10;
    auto y = 10; // y becomes int type
    std::map<std::string, std::string> m;
    std::map<std::string, std::string> *p = &m;
    auto *p1 = &m;
// ----------

    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    for(int i=0; i<10; ++i){
        std::cout << arr[i] << std::endl;
    }
    //std c++11
    for(int* i=std::begin(arr); i<std::end(arr); ++i){
        std::cout <<"p:" << i << "|" << *i << std::endl;
    }
    std::cout<<"End:"<<std::end(arr)<<std::endl;
    // Range based for loop
    for(auto element : arr){
        std::cout << "r:" << element << std::endl;
    }

}