#pragma once
#include"Payment.h"


class CreditCardPayment : public Payment
{
public:
	CreditCardPayment();
	//Parametized constructor to pass credit card information
	CreditCardPayment(float amt, std::string type, std::string name, std::string date, std::string number);
	void paymentDetails();
	std::string getName()const;
	std::string getExpDate()const;
	std::string getCardNum()const;
	int getPT()const;
private:
	int PT;
	std::string nameOnCard;
	std::string expiryDate;
	std::string crediCardNumber;
};
