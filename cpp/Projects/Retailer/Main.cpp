#include <iostream>
#include <fstream>
#include "Product.h"
#include "Customer.h"

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

void testProduct(bool addProduct=false){
    Product::setPath("./products");
    Product::load();
    if(addProduct)
    {
        std::shared_ptr<Product> product(new Product("Rice",40,45,20));
        std::shared_ptr<Product> product1(new Product("Sugar",50,55,10));
        Product::addProduct(product);
        Product::addProduct(product1);
    }
    Product::viewProduct(print);
    Product::viewProduct(print1);
    Product::unload();
}


void testCustomer(){
    std::shared_ptr<Customer> customer(new Customer("9012345678", "Rahul", "Jamtara"));
    Customer::addCustomer(customer);

    //get customer
    std::shared_ptr<Customer> ptr  = Customer::getCustomer("9012345678");
    if(ptr == nullptr)
        std::cout << "Customer doesn't exist" << std::endl;
    else
        std::cout << *ptr << std::endl;
}

#define TEST_PRODUCT 0
#define TEST_CUSTOMER 1


int main(int argc, char** argv){

#if TEST_PRODUCT==1
    bool addProduct = false;
    if(argc > 1 && std::string(argv[1]) == "-addProduct")
        addProduct = true;
    testProduct(addProduct);
#endif

#if TEST_CUSTOMER == 1
    testCustomer();
#endif


}