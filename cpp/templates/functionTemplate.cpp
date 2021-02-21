#include <iostream>

template<class dataType, class dataType2>
dataType sum(dataType a, dataType2 b)
{
    return a+b;
}


int main(){
    std::cout << sum<int,int>(2.4,5) << std::endl;
    std::cout << sum(2.4,5) << std::endl;
}