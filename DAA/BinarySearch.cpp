#include <vector>
#include <iostream>

int binarySearch(const std::vector<int>& list, int searchItem, int startingIndex, int endIndex)
{
    // [1,2,3,4,5]
    // [1,2,3] [4,5]
    //
    // [1,2,3,4]
    // [1,2] [3,4]
    int n = endIndex-startingIndex+1;
    if(n==1){
        if(list[startingIndex] == searchItem)
            return startingIndex;
        else
            return -1;
    }
    int subArraySize = n/2;
    int remainder = n%2;
    int lefSubArrayLastElementIndex = startingIndex + subArraySize+remainder-1;
    int index = -1;
    if(searchItem <= list[lefSubArrayLastElementIndex]){
        index = binarySearch(list, searchItem, startingIndex, lefSubArrayLastElementIndex);
    }
    else{
        index = binarySearch(list, searchItem, lefSubArrayLastElementIndex+1, endIndex);
    }
    return index;
}


int main()
{
    std::cout<<binarySearch({1,2,3,4,5,6,7,8,9,10}, 8, 0,9) << std::endl;
}
