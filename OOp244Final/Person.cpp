#include "Person.h"


Person::Person()
{
	nameOfperson = {};
	IDnum = 0;
	
	for (size_t i = 0; i < accountObj.size(); i++)
	{
		accountObj[i] = nullptr;
	}

	for (size_t i = 0; i < p.size(); i++)
	{
		p[i] = nullptr;
	}
	
}

Person::Person(std::string name, long id)
{
	nameOfperson = name;
	IDnum = id;
}

void Person::setPayment(std::vector<Payment*>& obj)
{
	for (size_t i = 0; i < obj.size(); i++)
	{
		p.push_back(obj[i]);
	}
}

void Person::setName(std::string name)
{
	nameOfperson = name;
}

void Person::setIDnum(long id)
{
	IDnum = id;
}

std::string Person::getName() const
{
	return nameOfperson;
}

long Person::getID() const
{
	return IDnum;
}
void Person::setAccount(Account* &accObj)
{
	accountObj.push_back(accObj);
	/*for (size_t i = 0; i < accObj.size(); i++)
	{
		accountObj.push_back(accObj[i]);
		//accountObj[i] = accObj[i];
	}*/
}

std::vector<Account*> Person::getAccounts()const
{
	return accountObj;
}

void Person::displayPerson()
{
	std::cout << "Name: " << nameOfperson << std::endl << "ID: " << IDnum << std::endl;
	
}

std::array<float, 6> Person::getCatAmt(int num)
{
	/*std::cout << std::setprecision(2);
	std::cout << std::fixed;*/
	std::array<std::string, 6> PayCat { "BILLS","SHOPPING","GROCERY","FUEL","MEDICINE","OTHERS" };
	std::array<float,6> total = { 0.0f };  // store total payments in an array
	std::array<float,6> CashAmt = { 0.0f }; // store sum of cash payment in an array 
	std::array<float,6> CreditAmt = {0.0f}; //store sum of credit payments in an array

	for (size_t i = 0; i < p.size(); i++)
	{
		for (size_t j = 0; j < PayCat.size(); j++)
		{
			if (p[i]->getPaymentType() == PayCat[j])
			{

				total[j] += p[i]->paymentAmount;
				if (p[i]->getPT() == 1)
				{
					CashAmt[j] += p[i]->getPaymentamt();
				}
				if (p[i]->getPT() == 2)
				{
					CreditAmt[j] += p[i]->getPaymentamt();
				}	
			}
			/*else
			{
				total[j] = 0.0f;
				CashAmt[j] = 0.0f;
				CreditAmt[j] = 0.0f;
			}*/
		}
		  
	}
	if (num == 1)
	{
		return total;
	}
	if (num == 2)
	{
		return CashAmt;
	}
	if (num == 3)
	{
		return CreditAmt;
	}


}

