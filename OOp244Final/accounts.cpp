#include "accounts.h"

Account::Account()
{
	acc_balance = 0.0;
}

Account::Account(double init_bal)
{
	if (init_bal >= 0.0)
	{
		acc_balance = init_bal;
	}
	else
	{
		std::cout << "Initial balance Invalid" << std::endl;
		acc_balance = 0.0;
	}
}

void Account::credit(double amt)
{
	acc_balance += amt;
}

bool Account::debit(double amt)
{    
	//validate withdrawal not to exceed account balance
	if (amt <= acc_balance)
	{
		acc_balance -= amt;
		return true;
	}
	else
	{
		std::cout << "Amount exceeded account balance!" << std::endl;
		return false;
	}
	
}

void Account::setBalance(double amt)
{
	acc_balance = amt;
}

double Account::getBalance() const
{
	return acc_balance;
}
