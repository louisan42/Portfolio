#include"CheckingAccounts.h"


CheckingAccount::CheckingAccount() : Account()
{
	feeCharged = 0;
}

CheckingAccount::CheckingAccount(double initialBalance, double fee): Account(initialBalance)
{
	feeCharged = fee;
}

void CheckingAccount::credit(double amt)
{   // Subtract fee from deposited amount to ensure fee is charged
	amt -= feeCharged;
	// validate to ensure transaction does not run out the account
	if (amt <= 0.0 && getBalance() <= 0.0)
	{
		std::cout << "Invalid transaction! Not enough balance!" << std::endl
			<< "Please deposit enough to cover $" << feeCharged << " transaction fee" << std::endl;
	}
	else
	{
		Account::credit(amt);
	}
	 
}

void CheckingAccount::setFee(double amt)
{
	feeCharged = amt;
}

bool CheckingAccount::debit(double amt)
{   // calculate total deductible to ensure fee can be charged as well
	amt += feeCharged;

	if (Account::debit(amt))
	{
		return true;
	}
	else
	{   // print additional statement 
		std::cout << "Or not enough balance to charge transaction fee!" << std::endl;
		return false;
	}
}

double CheckingAccount::getFeeCharged() const
{
	return feeCharged;
}
