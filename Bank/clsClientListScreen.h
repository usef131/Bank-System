#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <string>
#include "clsUser.h"

class clsClientListScreen : clsScreen
{
private:

	static void printeachclient(clsBankClient client)
	{
		cout << setw(15) << "               | " << setw(14) << client.AccountNumber();
		cout << "| " << left << setw(20) << client.FullName();
		cout << "| " << left << setw(11) << client.Phone;
		cout << "| " << left << setw(20) << client.Email;
		cout << "| " << left << setw(10) << client.PinCode;
		cout << "| " << left << setw(10) << client.AccountBalance << " | ";
	}

public:
	static void ShowallClientsList()
	{

		if (!AccesssRights(clsUser::enPermissions::pListClients))
			return;


		vector<clsBankClient> vclients = clsBankClient::ShowClientsList();

		string Title = "   Client List Screen";
		string SubTitle = "    (" + to_string(vclients.size()) + ") Client(s).";


		_PrintTitleofPage(Title, SubTitle);
	
		cout << "\n               ---------------------------------------------------------------------------------------------------\n";
		cout << setw(15)  << "               | " << setw(14) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(11) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(10) << "Balance" << " | ";
		cout << "\n               ---------------------------------------------------------------------------------------------------\n";
		if (vclients.size() == 0)
		{
			cout << "\t\t\t\tNo clients avilable in system\n";
		}
		else
		{
			for (clsBankClient& client : vclients)
			{
				printeachclient(client);
				cout << endl;
			}
		}
		cout << "               ---------------------------------------------------------------------------------------------------\n";
	}

};

