#include "Payment.h"

//CardPayment
CardPayment::CardPayment(double amount, const std::string& cardHolderName, 
        const std::string& lastFourDigitsOfCard, std::shared_ptr<Customer> customer)
{
    m_amount = amount;
    m_CardHolderName = cardHolderName;
    m_LastFourtDigitsOfCard = lastFourDigitsOfCard;
    m_Customer = customer;
}




//CashPayment
CashPayment::CashPayment(double amount, std::shared_ptr<Customer> customer)
{
    m_amount = amount;
    m_Customer = customer;
}

//Debt
Debt::Debt(double amount, std::shared_ptr<Customer> customer)
{
    m_amount = amount;
    m_Customer = customer;
}