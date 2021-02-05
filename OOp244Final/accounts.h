#pragma once
#include<iostream>


class Account
{
public:
	Account();
	Account(double init_bal);                   // parameterized constructor
	virtual void credit(double amt);
	virtual bool debit(double amt);
	void setBalance(double amt);
    double getBalance()const;  

private:
	// Declaring variables
	double acc_balance;
};