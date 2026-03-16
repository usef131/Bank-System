#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <string>
#include "clsUser.h"

class clsAddNewClient : protected clsScreen
{
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nPlease Enter your First Name : ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nPlease Enter your Last Name : ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nPlease Enter your Email : ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nPlease Enter your Phone : ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nPlease Enter your PinCode : ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nPlease Enter your AccountBalance : ";
		Client.AccountBalance = stol(clsInputValidate::ReadString());
	}
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

public :

	static void AddNewClient()
	{

		if (!AccesssRights(clsUser::enPermissions::pAddNewClient))
			return;

		_PrintTitleofPage("Add New Client Screen");
	

		string AccountNumber;

		cout << "Enter The Account Number To add it : ";
		AccountNumber = clsInputValidate::ReadString();

		while ((clsBankClient::IsclientExist(AccountNumber)))
		{
			cout << "\nThe Account Number you have added is Already Exist, Enter New Account Number: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewCLient = clsBankClient::GetAddNewClientObject(AccountNumber);
		_ReadClientInfo(NewCLient);

		clsBankClient::enSaveResults saveresult;

		saveresult = NewCLient.Save();

		switch (saveresult)
		{

		case  clsBankClient::enSaveResults::svSuccessed:
		{
			cout << "\nAccount Addeded Successfully :-)\n";
			_PrintClientCard(NewCLient);
			break;
		}

		case clsBankClient::enSaveResults::svFaild:
		{
			cout << "\nError account was not saved because it's Empty";
			break;
		}

		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;
		}

		}

	}

};

