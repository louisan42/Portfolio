#pragma once
#include"accounts.h"


class CheckingAccount :public Account
{
public:
	CheckingAccount();
	CheckingAccount(double initialBalance, double fee);
	void credit(double amt);
	void setFee(double amt);
	bool debit(double amt);
	double getFeeCharged()const;

private:
	double feeCharged;
};