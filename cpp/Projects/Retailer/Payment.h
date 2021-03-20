#ifndef __RETAILER__PAYMENT_H__
#define __RETAILER__PAYMENT_H__

#include <memory>
#include "Customer.h"
class Payment
{
public:
    virtual bool makePayment(double amount) = 0;
protected:
    std::shared_ptr<Customer> m_Customer;
};


class CardPayment : public Payment{
public:
    CardPayment(const std::string& cardHolderName, 
        const std::string& lastFourDigitsOfCard,
        std::shared_ptr<Customer> customer = nullptr);
public:
    bool makePayment(double amount) override;
private:
    std::string m_CardHolderName;
    std::string m_LastFourtDigitsOfCard;
};

class CashPayment : public Payment{
public:
    CashPayment(std::shared_ptr<Customer> customer = nullptr);
public:
    bool makePayment(double amount) override;
};

class Debt : public Payment{
public:
    Debt(std::shared_ptr<Customer> customer);
public:
    bool makePayment(double amount) override;
};



#endif