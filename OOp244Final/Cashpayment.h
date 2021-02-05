#pragma once
#include"Payment.h"


class CashPayment : public Payment
{
public:
	CashPayment();
	CashPayment(float amt, std::string type);
	void paymentDetails();
	int getPT()const;

private:
	int PT;
};
