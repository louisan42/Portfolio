#include "Cashpayment.h"

CashPayment::CashPayment() : Payment()
{
	PT = 1;
}

CashPayment::CashPayment(float amt, std::string type) : Payment(amt,type)
{
	PT = 1;
}

void CashPayment::paymentDetails()
{
	std::cout << "You have made a cash/debit payment of $" << getPaymentamt() << " towards " << getPaymentType() << std::endl;
}

int CashPayment::getPT() const
{
	return PT;
}
