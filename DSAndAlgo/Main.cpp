#include "UnionFind.h"
#include <iostream>

int main()
{
    UnionFind uf;
    uf.connect(2,3);
    uf.connect(6,7);
    uf.connect(5,6);
    uf.connect(5,8);
    std::cout<< uf << std::endl;
    std::cout<<"isConnected(3,6) :" << uf.isConnected(3,6)<<std::endl;
    std::cout<<"isConnected(5,7) :" << uf.isConnected(5,7)<<std::endl;
    return 0;
}