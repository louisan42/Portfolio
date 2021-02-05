#pragma once
#include"accounts.h"


class SavingsAccount : public Account
{

public:
	SavingsAccount();
	SavingsAccount(double initialBalance, double interestRate);
	double calculateInterest()const;

private:
	double interest_rate;
};
