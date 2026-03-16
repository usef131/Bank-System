#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "Globle.h"
#include "clsMainMenu.h"

class clsLoginScreen : protected clsScreen
{
	static void _Login()
	{

		string username, password;
		bool loginfailed = false;
		short trails = 3;


		do
		{

			if (loginfailed)
			{
				--trails;
				cout << "\nInvlaid Username/Password!\n";
				cout << "You have " << trails << " trails to login.\n\n";

				if (trails == 0)
				{
					cout << "\nYou are locked after 3 faild trails\n\n";
					exit(0);
				}
			}
			cout << "Enter your username : ";
			cin >> username;
			cout << "Enter your password : ";
			cin >> password;


			CurrentUser = clsUser::Find(username, password);
			loginfailed = CurrentUser.IsEmpty();

		} while (loginfailed);

		
		clsUser::saveLoginRegisterinfile(CurrentUser);
		clsMainMenu::ShowMainMenu();
	}

public :

	static void LoginScreen()
	{
		 system("cls");
		_PrintTitleofPage("     Login Screen");
		_Login();
	}


};

