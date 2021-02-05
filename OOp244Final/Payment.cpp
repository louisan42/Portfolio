#include "Payment.h"

Payment::Payment()
{
	PT = 0;
	paymentAmount = 0.0f;
	paymentType = {};
}

Payment::Payment(float amt, std::string type)
{
	PT = 0;
	paymentAmount = amt;
	paymentType = type;
}

void Payment::setPaymentAmt(float amt)
{
	paymentAmount = amt;
}

float Payment::getPaymentamt() const
{
	return paymentAmount;
}

void Payment::paymentDetails()
{
	std::cout << "You have made a " << paymentType << " payment in the amount of $" << paymentAmount << std::endl;
}

void Payment::setPaymentType(std::string payType)
{
	paymentType = payType;
}

std::string Payment::getPaymentType() const
{
	return paymentType;
}

int Payment::getPT() const
{
	return PT;
}
