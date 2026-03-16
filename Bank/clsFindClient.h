#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <string>
#include "clsUser.h"

class clsFindClient : protected clsScreen
{
private:

	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n______________________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n_____________________________\n\n";
	}


public:
	static void FindClinet()
	{

		if (!AccesssRights(clsUser::enPermissions::pFindClient))
			return;

		_PrintTitleofPage("Find Client Screen");
	
		string AccountNumber;
		cout << "PLease Enter your Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!(clsBankClient::IsclientExist(AccountNumber)))
		{
			cout << "\nSorry, This Cient is not Exist, Enter another Account Number: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClientCard(Client);



	}


};

