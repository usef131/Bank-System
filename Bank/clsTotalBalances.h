#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsUtility.h"
#include "clsScreen.h"
using namespace std;

class clsTotalBalances : protected clsScreen
{
	static void _printeachclient(clsBankClient client)
	{
		cout << setw(15)<< "" << "| " << left << setw(14) << client.AccountNumber();
		cout << "| " << left << setw(50) << client.FullName();
		cout << "| " << left << setw(12) << client.AccountBalance << "|";
	}

public:
	static void ShowTotalBalances()
	{
		_PrintTitleofPage("Show Total Balances Screen");



		vector<clsBankClient> vclients = clsBankClient::ShowClientsList();

		cout << "\n\t\t\t\t\t\t\t" << vclients.size() << " CLient(s)\n";

		cout << setw(15) << "" << "-----------------------------------------------------------------------------------\n";
		cout << setw(15) << "" << "| " << left << setw(14) << "Account Number";
		cout << "| " << left << setw(50) << "Client Name";
		cout << "| " << left << setw(30) << "Balance     |" ;
		cout << setw(20) << "" << "-----------------------------------------------------------------------------------\n";

		if (vclients.size() == 0)
		{
			cout << "\t\t\t\tNo clients avilable in system\n";
		}
		else
		{
			for (clsBankClient& client : vclients)
			{
				_printeachclient(client);
				cout << endl;
			}
		}
		cout << setw(15) << "" << "-----------------------------------------------------------------------------------\n";

		cout << "\t\t\t\t\t" << "\tTotal Balances : " << clsBankClient::SumofAllBalacnes();
		cout << "\t\t\t\t' " << clsUtility::numt_to_text(clsBankClient::SumofAllBalacnes()) << "'" << endl;

	}

};


