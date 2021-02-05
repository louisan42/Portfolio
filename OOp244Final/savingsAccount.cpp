#include "savingsAccount.h"

SavingsAccount::SavingsAccount() : Account()
{
}

SavingsAccount::SavingsAccount(double initialBalance, double interestRate): Account(initialBalance)
{
	interest_rate = interestRate;
}

double SavingsAccount::calculateInterest() const
{
	double intRate = getBalance() * (interest_rate / 100);
	return intRate;
}
