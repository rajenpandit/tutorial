#ifndef __RETAILER__PRODUCT_H__
#define __RETAILER__PRODUCT_H__

#include <memory>
#include <map>
#include <string>
#include <functional>
class Product{
public:
    //Constructors
    Product(const std::string& name, double cost, double sellingPrice, double m_quantity=0);
public:
    //static
    static bool load();
    static bool unload();
    static bool addProduct(std::shared_ptr<Product> product);
    static void viewProduct(std::function<void(std::shared_ptr<Product>)> fn);
private:
    unsigned int m_id;
    std::string m_name;
    double m_cost;
    double m_sellingPrice;
    unsigned int m_quantity;

    //static
    static unsigned int s_Id;
    static std::map<unsigned int, std::shared_ptr<Product>> s_productMap;

    //friend
    friend std::ostream& operator<<(std::ostream& os,std::shared_ptr<Product>);
};
#endif