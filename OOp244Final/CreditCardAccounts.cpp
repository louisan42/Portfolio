#include "CreditCardAccounts.h"



CreditCardAccounts::CreditCardAccounts() : Account()
{
	availableCredit = 0.0;
	creditCardLimit = 0.0;
	//leftToSpend = creditCardLimit - Account::getBalance();
}

CreditCardAccounts::CreditCardAccounts(double credit_limit, double debt) : Account(debt)
{
	availableCredit = 0.0;
	creditCardLimit = credit_limit;
	//leftToSpend = creditCardLimit - Account::getBalance();
}

void CreditCardAccounts::credit(double amount)
{
	//validate purchasing power
	if (amount<= availableCredit)
	{
		Account::credit(amount);
		calcAvailCredit();
	}
	else
	{
		std::cout << "Error! Your credit limit is $  " << creditCardLimit << std::endl
			<< "Your statement balance is $ " << Account::getBalance() << std::endl;
	}
	
	 
}

bool CreditCardAccounts::debit(double amount)
{
	if (Account::debit(amount))
	{
		calcAvailCredit();
		return true;
	}
	else
	{
		std::cout << "Process not completed, check message above" << std::endl;
		return false;
	}
	
}

void CreditCardAccounts::setCreditCardLimit(double cred_limit)
{
	creditCardLimit = cred_limit;
}

double CreditCardAccounts::getAvailCredit() const
{
	
	return availableCredit;
}

void CreditCardAccounts::calcAvailCredit()
{
	availableCredit = creditCardLimit - Account::getBalance();
}
