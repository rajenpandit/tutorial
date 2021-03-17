#ifndef __RETAILER__CUSTOMER_H__
#define __RETAILER__CUSTOMER_H__
#include <string>
#include <memory>
#include <map>
class Customer{
public:
    Customer(const std::string& phoneNumber,
        const std::string& name,
        const std::string& address);
public:
    /*
    * Get a customer object and store into a file.
    * File Name will be {m_phoneNumber}.txt
    */
    static bool addCustomer(std::shared_ptr<Customer> customer);

    /*
    * Take a phoneNumber as argument and read a file named {phoneNumber}.txt
    * create a Customer object using files content and return a shared_pointer.
    * Retrun nullptr if file is not found.
    */
    static std::shared_ptr<Customer> getCustomer(const std::string& phoneNumber);
private:
    std::string m_phoneNumber;
    std::string m_name;
    std::string m_address;
};
#endif