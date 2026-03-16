#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsUtility.h"
#include <string>

class clsListUsersScreen : protected clsScreen
{
	static void _printeachuser(clsUser user)
	{
		cout << setw(10) << "               | " << setw(14) << user.UserName;
		cout << "| " << left << setw(20) << user.FullName();
		cout << "| " << left << setw(11) << user.Phone;
		cout << "| " << left << setw(25) << user.Email;
		cout << "| " << left << setw(10) << user.Password;
		cout << "| " << left << setw(10) << user.Permissions << " | ";
	}

public:
	static void ShowallUsersList()
	{
		system("cls");

		vector<clsUser> vUsers = clsUser::ShowUsersList();

		string Title = "   User List Screen";
		string SubTitle = "     (" + to_string(vUsers.size()) + ") User(s).";


		_PrintTitleofPage(Title, SubTitle);


		cout << "\n               --------------------------------------------------------------------------------------------------------\n";
		cout << setw(10) << "               | " << setw(14) << "UserName";
		cout << "| " << left << setw(20) << "FullName";
		cout << "| " << left << setw(11) << "Phone";
		cout << "| " << left << setw(25) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(10) << "Permissions" << "| ";
		cout << "\n               --------------------------------------------------------------------------------------------------------\n";
		if (vUsers.size() == 0)
		{
			cout << "\t\t\t\tNo clients avilable in system\n";
		}
		else
		{
			for (clsUser& user : vUsers)
			{
				_printeachuser(user);
				cout << endl;
			}
		}
		cout << "               --------------------------------------------------------------------------------------------------------\n";
	}


};
