#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <string>
#include "clsUser.h"

class clsUpdateClient : protected clsScreen
{

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "Please Enter your First Name : ";
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
	static void UpdateClient()
	{

		if (!AccesssRights(clsUser::enPermissions::pUpdateClients))
			return;


		_PrintTitleofPage("Update Client Screen");
		

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

		cout << "\n---------------------\n";

		// For read the new informations
		_ReadClientInfo(Client);

		//enum datatype
		clsBankClient::enSaveResults SaveResults;

		SaveResults = Client.Save();

		switch (SaveResults)
		{
		case clsBankClient::enSaveResults::svFaild:
			cout << "\nError this Account will not be saved in the file :(";
			break;

		case clsBankClient::enSaveResults::svSuccessed:
			cout << "\nThe New Client info has Been updated Successfully :)";
			break;
		}

		cout << "\n";


		_PrintClientCard(Client);

	}


};

