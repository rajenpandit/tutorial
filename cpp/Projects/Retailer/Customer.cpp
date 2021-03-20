#include <fstream>
#include "Customer.h"


Customer::Customer(const std::string& phoneNumber,
        const std::string& name,
        const std::string& address){
    m_phoneNumber = phoneNumber;
    m_name = name;
    m_address = address;
}

bool Customer::addCustomer(std::shared_ptr<Customer> customer){
    if(customer == nullptr)
        return false;
    const std::string& fileName = "./customers/" + customer->m_phoneNumber + ".txt";
    std::fstream fs(fileName, fs.out);
    if(!fs.is_open())
        return false;
    fs << customer->m_name << " "
        << customer->m_address << "\n";
    fs.close();
    return true;
}
std::shared_ptr<Customer> Customer::getCustomer(const std::string& phoneNumber)
{
    const std::string& fileName = "./customers/" + phoneNumber + ".txt";
    std::fstream fs(fileName, fs.in);
    if(!fs.is_open())
        return nullptr;
    std::string name;
    std::string address;

    fs >> name >> address;
    fs.close();
    std::shared_ptr<Customer> customer(new Customer(phoneNumber,name, address));
    return customer;
}


std::ostream& operator << (std::ostream& os, const Customer& customer){
    os << customer.m_phoneNumber << "\n"
        << customer.m_name << "\n"
        << customer.m_address << "\n";
    return os;
}