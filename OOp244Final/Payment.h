#pragma once
#include<iostream>
//#include"Person.h"




class Payment
{
public:
	Payment();
	Payment(float amt, std::string type);
	void setPaymentAmt(float amt);
	float getPaymentamt() const;
	virtual void paymentDetails();
	void setPaymentType(std::string payType);
	std::string getPaymentType() const;
	virtual int getPT()const;
	friend class Person;

private:
	float paymentAmount;
	std::string paymentType;
	int PT;
};
