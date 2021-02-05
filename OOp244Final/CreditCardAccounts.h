#pragma once
#include"accounts.h"


class CreditCardAccounts :public Account
{
public:
	CreditCardAccounts();
	CreditCardAccounts(double credit_limit,double debt);
	void credit(double amount);
	bool debit(double amount);
	
	void setCreditCardLimit(double cred_limit);
	//double getOwingBalance()const;
	double getAvailCredit()const;
	void calcAvailCredit(); //this will calculate availble credit each time a transaction is made
	
	

private:
	double creditCardLimit;   // how much you owe on the credit card
	double availableCredit;  //
	
};
