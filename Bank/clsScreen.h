#pragma once
#include <iostream>
#include <iomanip>
#include "Globle.h"
#include "clsUser.h"
#include "clsDate.h"
#include <fstream>
using namespace std;

class clsScreen
{
protected:

	static void _PrintTitleofPage(string title , string subtitle = "")
	{
		cout << setw(37) <<  "" << "-------------------------------------------\n";
		cout << setw(25) <<  left << "" << "\t\t\t" << title << endl;
		if (subtitle != "")
		{
			cout << setw(25) << left << "" << "\t\t\t" << subtitle << endl;
		}
		cout << setw(37)  << "" << "-------------------------------------------\n";

		cout << "\t\t\t\t      User : " << CurrentUser.UserName << endl;
		cout << "\t\t\t\t      Date : " << clsDate::DatetoString(clsDate()) << "\n\n";

	}

	static bool AccesssRights(clsUser::enPermissions Permission)
	{
		if (!(CurrentUser.CheckPermission(Permission)))
		{
			cout << "\t\t\t\t\t______________________________________";
			cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
			cout << "\n\t\t\t\t\t______________________________________\n\n";
			return false;
		}
		else
		{
			return true;
		}
	}


};

