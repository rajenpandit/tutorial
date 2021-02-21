#include <iostream>

#define ARRAY_SIZE 20

template<class dataType, class dummyType>
class Array
{
public:
    void insertAt(int index, dataType data){
        arr[index] = data;
    }
    dataType getDataAt(int index){
        return arr[index];
    }
private:
    dataType arr[ARRAY_SIZE];
    dummyType _dummy;
};

int main(){
    Array<char,int> arr;
    std::cout << "SizeOf Array:" << sizeof(arr) << std::endl;
    for(int i=0; i<ARRAY_SIZE; ++i){
        arr.insertAt(i, i+65);
    }

    for(int i=0; i<ARRAY_SIZE; ++i){
        std::cout <<"data[" << i << "]" << arr.getDataAt(i) << "\n";
    }
}