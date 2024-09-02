#include <utility>
#include <vector>
#include <iostream>


std::pair<int, int> minMaxDivide(std::vector<int> a)
{
    int subArraySize = a.size()/2;
    if(subArraySize > 0){
        std::vector<int> subArrayLeft;
        subArrayLeft.assign(a.begin(), a.begin()+subArraySize);

        std::vector<int> subArrayRight;
        subArrayRight.assign(a.begin()+subArraySize,a.end());
        auto leftPair = minMaxDivide(subArrayLeft);
        auto rightPair= minMaxDivide(subArrayRight);
        int min = leftPair.first;
        int max = leftPair.second;
        if(min > rightPair.first)
            min = rightPair.first;
        if(max < rightPair.second)
            max = rightPair.second;
        return std::make_pair(min, max);
    }
    return std::make_pair(a[0], a[0]);
}


int main() 
{
    std::vector<int> list = {4,5,1,60,7,2,1,8,9,10,3};
    auto pair = minMaxDivide(list);
    std::cout<<"Min:"<< pair.first << " | Max: "<< pair.second << std::endl;
}
