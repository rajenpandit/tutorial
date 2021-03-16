#include <iostream>
#include <fstream>
#include "Product.h"

void print(std::shared_ptr<Product> product){
    static std::fstream fs;
    if(!fs.is_open())
        fs.open("product.txt", fs.out | fs.app);
    // std::cout << product << std::endl;
    // std::cout << "______________________________"<< std::endl;
    fs << product << std::endl;
    fs << "______________________________"<< std::endl;
}
void print1(std::shared_ptr<Product> product){
    std::cout << product << std::endl;
    std::cout << "______________________________"<< std::endl;
}
int main(int argc, char** argv){
    Product::load();
    // if(argc > 1 && std::string(argv[1]) == "-addProduct")
    // {
    //     std::shared_ptr<Product> product(new Product("Rice",40,45,20));
    //     std::shared_ptr<Product> product1(new Product("Sugar",50,55,10));
    //     Product::addProduct(product);
    //     Product::addProduct(product1);
    // }
    Product::viewProduct(print);
    Product::viewProduct(print1);
    Product::unload();
}