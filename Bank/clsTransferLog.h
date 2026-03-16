#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <string>
#include "clsUser.h"
#include "Globle.h"
#include <vector>

class clsTransferLog : protected clsScreen
{
	static void _printeachTransferLog(clsBankClient::stTransferLog OP)
	{
		cout << setw(12) << "               | " << setw(25) << OP.DateandTime;
		cout << "| " << left << setw(10) << OP.sourceAccount;
		cout << "| " << left << setw(10) << OP.DilverdAccount;
		cout << "| " << left << setw(10) << OP.Amount ;
		cout << "| " << left << setw(10) << OP.SourceBalance ;
		cout << "| " << left << setw(10) << OP.DilverdBalance ;
		cout << "| " << left << setw(10) << OP.User << "|";
	}

public:

	static void ShowTransferLog()
	{
		vector <clsBankClient::stTransferLog> vTransfer = clsBankClient::SaveAllTransfer();

		string SubTitle = "    (" + to_string(vTransfer.size()) + ") Record(s).";

		_PrintTitleofPage("Transfer Log list screen", SubTitle);

		cout << "\n               ----------------------------------------------------------------------------------------------------\n";
		cout << setw(12) << "               | " << setw(25) << "Date/Time";
		cout << "| " << left << setw(10) << "S.Acct";
		cout << "| " << left << setw(10) << "D.Acct";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "S.Balance";
		cout << "| " << left << setw(10) << "D.Balance";
		cout << "| " << left << setw(10) << "User" << "|";
		cout << "\n               ----------------------------------------------------------------------------------------------------\n";

		if (vTransfer.size() == 0)
		{
			cout << "\t\t\t\tNo Records avilable in system\n";
		}
		else
		{
			for (clsBankClient::stTransferLog& OP : vTransfer)
			{
				_printeachTransferLog(OP);
				cout << endl;
			}
		}
		cout << "               ----------------------------------------------------------------------------------------------------\n";





	}




};

