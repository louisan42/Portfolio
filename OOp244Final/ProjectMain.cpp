#include<iostream>
#include<array>
#include"accounts.h"
#include"CheckingAccounts.h"
#include"savingsAccount.h"
#include"CreditCardAccounts.h"
#include"Person.h"
#include"Payment.h"
#include"Cashpayment.h"
#include"CreditCardPayment.h"

void inputValidate();      //input validation function




int main()
{
	bool exit = false;
	char selectMenu = 0;
	int option = 0;
	float amount = 0.0f;
	CashPayment cashP;
	CreditCardPayment CcPay;
	// put payment types in array to pass to class function
	// set array[0] to empty string, makes passing payment type easier. 
	std::array<std::string, 6> PayType = { "BILLS","SHOPPING", "GROCERY", "FUEL","MEDICINE","OTHER" };

	//A.2
	//test code for payment class

	std::cout << "---------------------------------------------------------------------------" << std::endl
		<< "WELCOME TO WESTLINKS PAYMENT MANAGEMENT SYSTEM" << std::endl
		<< "---------------------------------------------------------------------------" << std::endl
		<< "MENU OPTIONS: " << std::endl
		<< "1- CASH/DEBIT PAYMENT" << std::endl << "2- CREDIT CARD PAYMENT" << std::endl << "3- EXIT" << std::endl;
	while (!exit)
	{
		std::cout << std::endl << "PLEASE SELECT MENU: ";
		std::cin >> selectMenu;
		switch (selectMenu)
		{
		case '1':
		{
			std::cout << "-----------------------------------" << std::endl
				<< "CASH/DEBIT PAYMENT" << std::endl
				<< "-----------------------------------" << std::endl;
			std::cout << "WHAT ARE YOU PAYING FOR? " << std::endl;
			for (size_t i = 0; i < PayType.size(); i++)
			{
				std::cout << i+1 << "- " << PayType[i] << std::endl;
			}
			do
			{
				std::cout << std::endl << "ENTER OPTION: ";
				std::cin >> option;
				inputValidate();
				if (option < 1 || option > 6)
				{
					std::cout << "OPTION MENU IS 1-6!" << std::endl << "PLEASE TRY AGAIN" << std::endl;
				}

			} while (option < 1 || option > 6);
			
			// set payment type
			cashP.setPaymentType(PayType[option-1]);
			do
			{
				
				std::cout << "Enter amount: $";
				std::cin >> amount;
				inputValidate();
				

			} while (!std::cin);
			// set amount
			cashP.setPaymentAmt(amount);
			//print Payment details
			cashP.paymentDetails();
			std::cout << "==========================================================================================" << std::endl;
			break;

		}
		case '2':
			std::cout << "-----------------------------------" << std::endl
				<< "CREDIT CARD PAYMENT" << std::endl
				<< "-----------------------------------" << std::endl;
			std::cout << "WHAT ARE YOU PAYING FOR? " << std::endl;
			for (size_t i = 1; i < PayType.size(); i++)
			{
				std::cout << i+1 << "- " << PayType[i] << std::endl;
			}
			do
			{
				std::cout << std::endl << "ENTER OPTION: ";
				std::cin >> option;
				if (option < 1 || option > 6 || !std::cin)
				{
					std::cout << "Invalid input! NUMBERS ONLY(1-6)!" << std::endl;
					std::cin.clear();
					std::cin.ignore(INT_MAX, '\n');  //flush input if garbage
				}

			} while (option < 1 || option > 6 || !std::cin); // validate input for range and proper data type
			// set payment type
			CcPay.setPaymentType(PayType[option-1]);
			do
			{
				std::cout << "Enter amount: $";
				std::cin >> amount;
				if (!std::cin)
				{
					std::cout << "Check Input!" << std::endl;

					std::cin.clear();
					std::cin.ignore(INT_MAX, '\n');
				}

			} while (!std::cin);
			
			// set amount
			CcPay.setPaymentAmt(amount);
			//print Payment details
			CcPay.paymentDetails();
			std::cout << "==========================================================================================" << std::endl;
			break;
		case '3':
			std::cout << std::endl << "Thank you for using WESTLINKS PMS! Bye" << std::endl;
			exit = true;
			break;

		default:
			std::cout << std::endl << "Invalid option!" << std::endl << "Please refer to MENU OPTIONS" << std::endl;
		}

	}// end of Payment system test
	std::cout << std::endl;



	//person instance
	std::string name = {};
	long iD = 0;
	unsigned int accSize = 0;
	unsigned int aaChoice = 0;
	
	//B.2
	std::cout << "Enter Person's Name: ";
	std::getline(std::cin,name);
	
	do
	{
		
		std::cout << "Enter Person's ID number: ";
		std::cin >> iD;
		if (!std::cin)
		{
			std::cout << "Invalid input! ID is numbers only!" << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}
		
	} while (!std::cin);
	Person john(name, iD);
	//get number of accounts
	
	do
	{
		
		std::cout << "How many Accounts does user have(max 3 Accounts): ";
		std::cin >> accSize;
		if (accSize > 3)
		{
			std::cout << "Maximum Account size is 3!" << std::endl;
		}
		else if(!std::cin)
		{
			std::cout << "Invalid entry!" << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}

	} while (!std::cin || accSize > 3);
	// USING VECTORS BECAUSE IT IS CAPABLE OF SHRINKING AND EXPANDING WHEN NEEDED
	std::vector<Account*> accObj; 
	double balance;
	double debt;
	//B.2 & C.2 has same solution
	for (size_t i = 0; i < accSize; i++)
	{

		do
		{
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << "---------------------------------" << std::endl;
			std::cout << "SELECT ACCOUNT " << i + 1 << " TYPE\t\t| " << std::endl
				<< "---------------------------------" << std::endl
				<< "1- Savings account" << std::endl << "2- Checking account" << std::endl << "3- Credit Card account" << std::endl << std::endl
				<< "YOUR INPUT: ";
			std::cin >> aaChoice;
			switch (aaChoice)
			{
			case 1:
			{
				accObj.push_back(new SavingsAccount(0, 4.5));
				std::cout << "-----------------------------------" << std::endl
					<< "SAVINGS ACCOUNT SETUP" << std::endl
					<< "-----------------------------------" << std::endl;
				std::cout << "ENTER INITIAL BALANCE: ";
				std::cin >> balance;
				SavingsAccount* savPtr = static_cast<SavingsAccount*>(accObj[i]);
				savPtr->setBalance(balance);
				std::cout << "Account Title: " << john.getName() << std::endl
					<< "Account Type: Savings Account " << std::endl
					<< "Interest earned: " << savPtr->calculateInterest() << std::endl;
				break;
			}
			case 2:
			{
				accObj.push_back(new CheckingAccount(0, 2.99));
				std::cout << "-----------------------------------" << std::endl
					<< "CHECKING ACCOUNT SETUP" << std::endl
					<< "-----------------------------------" << std::endl;
				std::cout << "ENTER INITIAL BALANCE: ";
				std::cin >> balance;
				CheckingAccount* chkPtr = static_cast<CheckingAccount*>(accObj[i]);
				chkPtr->setBalance(balance);
				std::cout << "Account Title: " << john.getName() << std::endl;
				std::cout << "Account Type: Checking Account " << std::endl
					<< "Transaction fee: " << chkPtr->getFeeCharged() << std::endl;
				break;
			}

			case 3:
			{
				accObj.push_back(new CreditCardAccounts);
				std::cout << "-----------------------------------" << std::endl
					<< "CREDIT CARD ACCOUNT SETUP" << std::endl
					<< "-----------------------------------" << std::endl;
				std::cout << "ENTER CREDIT LIMIT: ";
				std::cin >> balance;
				std::cout << "ENTER AMOUNT OWING ON CREDIT CARD: ";
				std::cin >> debt;
				CreditCardAccounts* ccPtr = static_cast<CreditCardAccounts*>(accObj[i]);
				ccPtr->setCreditCardLimit(balance);
				ccPtr->setBalance(debt);
				ccPtr->calcAvailCredit();
				std::cout << "Account Title: " << john.getName() << std::endl;
				std::cout << "Account Type: Credit Card Account " << std::endl
					<< "Available Credit: $" << ccPtr->getAvailCredit() << std::endl;
				break;
			}
			default:
				std::cout << "Invalid selection!" << std::endl;
				break;
			}
			
		} while (aaChoice > 3 || !std::cin);
		
		john.setAccount(accObj[i]);
		std::cout << "Account Balance: $" << john.getAccounts()[i]->getBalance() << std::endl
			<< "==================================================================================" << std::endl << std::endl;
	}
		
			
	
	for (size_t i = 0; i < accObj.size(); i++)
	{
		delete accObj[i];

	}

///////////////////////////////////////////////////////////////////////////////////////////////////




	std::vector<Payment*> pay;
	pay.push_back(new CashPayment(65.32f, "BILLS"));
	pay.push_back(new CashPayment(25.32f, "OTHERS"));
	pay.push_back(new CreditCardPayment(75.32f, "BILLS","John Lukas","12/06/2024","5423698741"));
	pay.push_back(new CashPayment(15.32f, "SHOPPING"));
	pay.push_back(new CreditCardPayment(78.32f, "SHOPPING", "John Lukas", "12/06/2024", "5423698741"));
	pay.push_back(new CashPayment(25.32f, "OTHERS"));
	pay.push_back(new CashPayment(63.32f, "MEDICINE"));
	std::vector<Person> PersonRow;
	//PersonRow.push_back(Person());  //call defalt to deisplay initital values
	PersonRow.push_back(Person("John Lukas", 4526369)); // set pVec[1]       // design is to match user sselection
	PersonRow.push_back(Person("Solomon Cowell", 9632547)); // set pVec[2]
	PersonRow.push_back(Person("Kim Hertz", 1547896));
	PersonRow.push_back(Person("Tilly Zicks", 1256987));
	PersonRow[0].setPayment(pay);
	
	std::vector<std::string>paymentDetail;
	std::array<float, 6> tt;
	std::array<float, 6> casht;
	std::array<float, 6> cct;
	std::string str, str1, str2;
	std::array<std::string, 6> PayCat{ "BILLS","SHOPPING","GROCERY","FUEL","MEDICINE","OTHERS" };
	//std::cout <<  << "\n";  //std::endl;
	for (size_t i = 0; i < PersonRow.size(); i++)
	{
		tt = PersonRow[i].getCatAmt(1);
		casht = PersonRow[i].getCatAmt(2);
		cct = PersonRow[i].getCatAmt(3);
		
		for (size_t j = 0; j < tt.size(); j++)
		{
			// convert total, cas amount and credit amount from float to tring to facilitate printing
			str += "\n========= " + PayCat[j] + " ===========" "\nTotal: $" + std::to_string(tt[j]) +"\nCash: $" + std::to_string(casht[j]) + "\nCredit Card: $" + std::to_string(cct[j]);
			//str1 += "Cash: $" + std::to_string(casht[i]) + "\t";
			//str2 +="Credit: $" + std::to_string(cct[i]) + "\t";
			
		}
		paymentDetail.push_back(str);
		// reset temp containers
		str = '\0';
		tt = { '\0' };
		casht = { '\0' };
		cct = { '\0' };
		 // concatenate the 3 strings and store in vector;
		
		//str1 = '\0';
		//str2 = '\0';
	
	}
	
	
	std::vector<std::string> name_id;
	long id;
	std::string info;
	for (size_t i = 0; i < PersonRow.size(); i++)
	{
		id = PersonRow[i].getID();
		info = PersonRow[i].getName() + "\n" + std::to_string(id);
		name_id.push_back(info);
		info = "\0";
	}
	
	/*std::cout << std::setprecision(2);
	std::cout << std::fixed;
	std::cout << name_id[0] << "\n" << paymentDetail[5] << std::endl;*/

	std::vector<std::vector<std::string>> v2d;
	v2d.push_back(name_id);
	v2d.push_back(paymentDetail);
	
	
	do
	{

	} while (!exit);
	



	for (size_t i = 0; i < v2d.size(); i++)
	{
		for (size_t j = 0; j < v2d[i].size(); j++)
		{
			
			
			std::cout << v2d[0][j];
			std::cout << v2d[1][j] << "\n";
			std::cout<<"----------------------------------------------------------------------\n";
			
		}

	}

	//std::cout << v2d[0][1]<<"\t\t"<< v2d[1][0];



		//std::vector<float>  ptr = static_cast < std::vector<std::string>>(tt);

	








	return 0;
}

void inputValidate()
{
	if (!std::cin)      // check input stream for right data type
	{
		std::cout << "Invalid Input!" << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
}
