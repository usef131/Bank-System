#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

class clsCureencyCalc : protected clsScreen
{

	static void _PrintClientCard(clsCurrency Currency)
	{

		cout << "\n______________________________\n";
		cout << "\n    country  : " << Currency.Country();
		cout << "\n    Code     : " << Currency.CurrencyCode();
		cout << "\n    Name     : " << Currency.CurrencyName();
		cout << "\n    Rate(1$) : " << Currency.Rate();
		cout << "\n______________________________\n\n";
	}
	static clsCurrency _GetCurrency(string Message)
	{

		string CurrencyCode;
		cout << Message;

		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;

	}
	static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		cout << "Convert From: \n";
		_PrintClientCard(Currency1);

		float AmountInUSD = Currency1.CovertToUSD(Amount);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInUSD << " USD\n";

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting from USD to:\n";
		cout << "\nTo: \n";
		_PrintClientCard(Currency2);

		float AmountInCurrrency2 = Currency1.ConverttoOtherCurrency(Currency2 , Amount);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInCurrrency2 << " " << Currency2.CurrencyCode() << endl;

	}



public :

	static void CurrencyCalaulator()
	{
		_PrintTitleofPage(" Currency Calc. Screen");
		char userans;

		do
		{
			system("cls");
			_PrintTitleofPage(" Currency Calc. Screen");

			clsCurrency Currency1 = _GetCurrency("\nPlease Enter Currency1 Code: ");
			clsCurrency Currency2 = _GetCurrency("\nPlease Enter Currency2 Code: ");

			cout << "\nEnter Amount to Exchange: ";
			float amount = clsInputValidate::ReadfltNumber();

			cout << endl;

			_PrintCalculationsResults(amount, Currency1, Currency2);


			cout << "\nDo you Want to do perform another calculation (Y | N) : ";
			userans = clsInputValidate::Readchar();
		     

		} while (userans == 'y' || userans == 'Y');



	}




};

