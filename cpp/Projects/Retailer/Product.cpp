#include <ostream>
#include <fstream>
#include "Product.h"

std::map<unsigned int, std::shared_ptr<Product>> Product::s_productMap;
unsigned int Product::s_Id = 1000;

Product::Product(const std::string& name, double cost, 
            double sellingPrice, double quantity) :
        m_name(name), 
        m_cost(cost),
        m_sellingPrice(sellingPrice),
        m_quantity(quantity)
{

}

//static
bool Product::load(){
    std::fstream fs("metadata.txt",fs.in);
    if(!fs.is_open())
        return false;
    unsigned int productId;
    fs >> productId;
    fs.close();
    unsigned int pId;
    std::string pName;
    double pCost;
    double pSellingPrice;
    unsigned int id = 1000;
    while(id <= productId){
        id++;
        std::string fileName = std::to_string(id) + ".txt";
        fs.open(fileName, fs.in);
        fs >> pId 
            >> pName 
            >> pCost
            >> pSellingPrice;
        std::shared_ptr<Product> product(new Product(pName,pCost,pSellingPrice));
        product->m_id = pId;
        s_productMap.emplace(pId,product);
        fs.close();
    }
    s_Id = id;
    return true;
}
bool Product::unload()
{
    std::fstream fs("metadata.txt",fs.out);
    if(!fs.is_open())
        return false;
    fs << s_Id;
    fs.close();

    for(auto p : s_productMap){
        std::string fileName = std::to_string(p.first) + ".txt";
        fs.open(fileName, fs.out);
        auto product = p.second;
        fs << product->m_id
            << " " << product->m_name
            << " " << product->m_cost
            << " " << product->m_sellingPrice;
        fs.close();
    }
    return true;
}
bool Product::addProduct(std::shared_ptr<Product> product){
    product->m_id = s_Id + 1;
    if(s_productMap.emplace(product->m_id,product).second == false)
        return false;
    s_Id += 1;
    return true;
}
void Product::viewProduct(std::function<void(std::shared_ptr<Product>)> fn)
{
    for(auto p : s_productMap){
        fn(p.second);
    }
}

//friend

std::ostream& operator<<(std::ostream& os,std::shared_ptr<Product> product){
    os << "Product ID:" << product->m_id << "\n";
    os << "Product Name:" << product->m_name << "\n";
    os << "Product Cost:" << product->m_cost << "\n";
    os << "Product Selling Price:" << product->m_sellingPrice;
    return os;
}