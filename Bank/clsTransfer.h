#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <string>
#include "clsUser.h"
#include "Globle.h"

class clsTransfer : protected clsScreen
{
	static void _PrintCard(clsBankClient client)
	{
		cout << "\nClient Card: ";
		cout << "\n_____________________\n";
		cout << "\nFull Name    : " << client.FullName();
		cout << "\nAcc. Number  : " << client.AccountNumber();
		cout << "\nAcc. Balance : " << client.AccountBalance;
		cout << "\n_____________________\n";

	}

public :

	static void Transfermoney()
	{
		_PrintTitleofPage(" Transfer Screen");


		cout << "\nPlease Enter Account Number to Transfer From : ";
		string AccountNumber1 = clsInputValidate::ReadString();
		clsBankClient client1 = clsBankClient::Find(AccountNumber1);
		_PrintCard(client1);
	    
		cout << "\nPlease Enter Account Number to Transfer to : ";
		string AccountNumber2 = clsInputValidate::ReadString();
		clsBankClient client2 = clsBankClient::Find(AccountNumber2);
		_PrintCard(client2);

		cout << "\nEnter Transfer amount : ";
		double money = clsInputValidate::ReadDblNumber();

		while (money > client1.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount : ";
			money = clsInputValidate::ReadDblNumber();
		}

		char userans = 'y';
		cout << "\nAre you sure you want to perform this opreation? (y|n) : ";
		userans = clsInputValidate::Readchar();

		if (userans == 'y' || userans == 'Y')
		{
		   client1.Transfermoneyto(client2 , money);

		   cout << "\nTransfer done successfully...\n\n";
		   _PrintCard(client1);
		   cout << endl;
		   _PrintCard(client2);
		}
		else
		{
			cout << "\nTransfer has been cancelled thank you...";
		}
		


	}

};

