#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include <iomanip>

class clsShowCurrencyList : protected clsScreen
{
	static void _printeachcurrency(clsCurrency Curr)
	{
		cout << setw(10) << "               | " << setw(30) << Curr.Country();
		cout << "| " << left << setw(6) << Curr.CurrencyCode();
		cout << "| " << left << setw(42) << Curr.CurrencyName();
		cout << "| " << left << setw(10) << Curr.Rate() << "  | ";

	}


public :

    static void ShowAllCurrenciesList()
	{
		system("cls");

		vector<clsCurrency> vCurrency = clsCurrency::GetCurrencyList();

		string Title = "   Currencies List Screen";
		string SubTitle = "     (" + to_string(vCurrency.size()) + ") Currency(s).";


		_PrintTitleofPage(Title, SubTitle);


		cout << "\n               ---------------------------------------------------------------------------------------------------\n";
		cout << setw(10) << "               | " << setw(30) << "Country";
		cout << "| " << left << setw(6) << "Code";
		cout << "| " << left << setw(42) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)" << "  | ";
		cout << "\n               ---------------------------------------------------------------------------------------------------\n";
		if (vCurrency.size() == 0)
		{
			cout << "\t\t\t\tNo Currencies avilable in system\n";
		}
		else
		{
			for (clsCurrency& Curr : vCurrency)
			{
				_printeachcurrency(Curr);
				cout << endl;
			}
		}
		cout << "               ---------------------------------------------------------------------------------------------------\n";
	}
};

