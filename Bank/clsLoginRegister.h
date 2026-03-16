#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <string>
#include "clsUser.h"
#include "Globle.h"

class clsLoginRegister :protected clsScreen
{
	static void _printeachLoginUser(clsUser::stLoginRegister client)
	{
		cout << setw(15) << "               | " << setw(25) << client.Dateandtime;
		cout << "| " << left << setw(15) << client.username;
		cout << "| " << left << setw(15) << client.password;
		cout << "| " << left << setw(15) << client.permissions << "|";
	}

public :

	static void showLoinRegister()
	{
		if (!AccesssRights(clsUser::enPermissions::pLoginRegister))
			return;

		vector<clsUser::stLoginRegister> vALlLogin = clsUser::ReadLogininfo();
		string SubTitle = "    (" + to_string(vALlLogin.size()) + ") Record(s).";

		_PrintTitleofPage("Login Register list screen" , SubTitle);

		cout << "\n               -------------------------------------------------------------------------------\n";
		cout << setw(15) << "               | " << setw(25) << "Date/Time";
		cout << "| " << left << setw(15) << "UserName";
		cout << "| " << left << setw(15) << "Password";
		cout << "| " << left << setw(15) << "Permissions" << "|";
		cout << "\n               -------------------------------------------------------------------------------\n";
		if (vALlLogin.size() == 0)
		{
			cout << "\t\t\t\tNo Records avilable in system\n";
		}
		else
		{
			for (clsUser::stLoginRegister& client : vALlLogin)
			{
				_printeachLoginUser(client);
				cout << endl;
			}
		}
		cout << "               -------------------------------------------------------------------------------\n";




	}


};

