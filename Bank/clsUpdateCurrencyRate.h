#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

class clsUpdateCurrencyRate : protected clsScreen 
{
	static void _PrintClientCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n______________________________\n";
		cout << "\n     country  : " << Currency.Country();
		cout << "\n     Code     : " << Currency.CurrencyCode();
		cout << "\n     Name     : " << Currency.CurrencyName();
		cout << "\n     Rate(1$) : " << Currency.Rate();
		cout << "\n______________________________\n\n";
	}


public : 

	static void UpdateCurrency()
	{
		_PrintTitleofPage(" Update Currency Screen");

		cout << "\nPlease Enter Currency Code : ";
		string CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found , choose another one : ";
			CurrencyCode = clsInputValidate::ReadString();
		}


		clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);
		_PrintClientCard(Currency1);

		cout << "\nAre you sure you want to update the rate of this currency (y | n) : ";
		char userans = clsInputValidate::Readchar();

		if (userans == 'y' || userans == 'Y')
		{

			cout << "\nUpdate Currency Rate:";
			cout << "\n______________________________\n\n";

			cout << "Enter New Rate : ";
			float NewRate = clsInputValidate::ReadfltNumber();

			Currency1.UpdateRate(NewRate);

			cout << "\nCurrency Rate Updated Successfully :-)\n";

			_PrintClientCard(Currency1);

			cout << endl;

		}
		else
			cout << "\nCurrency update is failed , Thank you....";


	}


};

