#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

class clsFindCurrency : protected clsScreen
{


	static void _PrintClientCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n  ______________________________\n";
		cout << "\n     country  : " << Currency.Country();
		cout << "\n     Code     : " << Currency.CurrencyCode();
		cout << "\n     Name     : " << Currency.CurrencyName();
		cout << "\n     Rate(1$) : " << Currency.Rate();
		cout << "\n  ______________________________\n\n";
	}

	static void _ShowResults(clsCurrency Currency)
	{

		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintClientCard(Currency);
		}
		else
		{
			cout << "\nCurrency Not Found :-(\n";
		}
	}


public : 


	static void FindCurrency()
	{
		_PrintTitleofPage(" Find Currency Screen");

		cout << "Find By: [1] Code or [2] Country ? ";
		int userans = clsInputValidate::ReadIntNumberbetween(1 , 2);

		switch(userans)
		{
		case 1:
		{
			cout << "\nPlease Enter Currency Code : ";
			string CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency1);
			break;
		}	
		case 2:
		{
			cout << "\nPlease Enter Country Name : ";
			string CountryName = clsInputValidate::ReadString();
			clsCurrency Currency2 = clsCurrency::FindByCountry(CountryName);
			_ShowResults(Currency2);
		     
			break;

		}	
		}



	}


};

