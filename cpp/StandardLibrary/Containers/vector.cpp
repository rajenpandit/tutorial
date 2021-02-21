#include <vector>
#include <iostream>

int main(){
    std::vector<int> v = {1,2,3,4};
    try  // exceptin handling
    {
        std::cout << v.at(200) << std::endl;
    }
    catch(...){
        std::cout << "data is not present at 200" << std::endl;
    }
    for(int i=5; i<15; ++i){
        v.push_back(i+5);
    }
    std::cout << "Size of vector:" << sizeof(v) << std::endl;
    std::cout << "Number of elements in vector:" << v.size() << std::endl;
    for(int i=0; i<v.size(); ++i){
        std::cout << v[i] << std::endl;
    }
}