#pragma once
#include <iostream>
#include <string>
#include <vector>
#include"accounts.h"
#include<iomanip>
#include<array>
#include"Payment.h"


class Person
{
public:
	Person();
	Person(std::string name, long id);
	std::vector<Payment*> p;
	void setPayment(std::vector<Payment*>&obj);
	void setName(std::string name);
	void setIDnum(long id);
	std::string getName() const;
	long getID() const;
	void setAccount(Account* &arrObj);
	std::vector<Account*> getAccounts()const;
	void displayPerson();
	std::array<float,6> getCatAmt(int num);  // added function to get totals (incl. cash and credit) of each category 
	                                           // num will decide with mant to return; 1- total spent 2- cash amount spent 3- credit amount spent

private:
	std::string nameOfperson;
	long IDnum;
	std::vector<Account*> accountObj;

};
