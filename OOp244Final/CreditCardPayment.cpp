#include "CreditCardPayment.h"

CreditCardPayment::CreditCardPayment() : Payment()
{
	PT = 2;
}

CreditCardPayment::CreditCardPayment(float amt, std::string type, std::string name, std::string date, std::string number) : Payment(amt, type)
{
	PT = 2;
	nameOnCard = name;
	expiryDate = date;
	crediCardNumber = number;
}

void CreditCardPayment::paymentDetails()
{
	
	std::cout << std::endl<<"You have made a credit card payment in the amount of $" << getPaymentamt() << " towards " << getPaymentType() << std::endl;

}

std::string CreditCardPayment::getName() const
{
	return nameOnCard;
}

std::string CreditCardPayment::getExpDate() const
{
	return expiryDate;
}

std::string CreditCardPayment::getCardNum() const
{
	return crediCardNumber;
}

int CreditCardPayment::getPT() const
{
	return PT;
}
