#pragma once
#include <iostream>
#include "clsDate.h"
#include "clsString.h"

using namespace std;

class clsInputValidate
{
public :

	static bool IsNaumberBetween(int number, int from, int to)
	{
		return (number >= from && number <= to);
	}
	static bool IsNumberBetween(double number, double from, double to)
	{
		return (number >= from && number <= to);
	}
	static bool IsDateBetween(clsDate currentdate , clsDate date1 , clsDate date2)
	{
		if (clsDate::IsDateonebeforedatetwo(date1, date2))
		{
			return (clsDate::IsDateoneAfterdatetwo(currentdate, date1) && clsDate::IsDateonebeforedatetwo(currentdate, date2));
		}
		else
		{
			return (clsDate::IsDateoneAfterdatetwo(currentdate, date2) && clsDate::IsDateonebeforedatetwo(currentdate, date1));
		}
	}
	static int ReadIntNumber(string message)
	{
		int x;
		cin >> x;
		while(cin.fail())
		{ 
			cout << message;
			cin.clear(); 
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			cin >> x;
		}
		return x;
	}
	static int ReadIntNumberbetween(int from , int to , string message = "")
	{
		int x;
		cout << message;
		cin >> x;

		while (x < from || x > to)
		{
			cout << "Invalid Number...\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << message;
			cin >> x;
		}
		return x;
	}
	static double ReadDblNumber()
	{
		double x;
		cin >> x;
		while (cin.fail())
		{

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> x;
		}
		return x;
	}

	static float ReadfltNumber()
	{
		float x;
		cin >> x;
		while (cin.fail())
		{

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> x;
		}
		return x;
	}

	static double ReadDblNumberbetween(double from, double to, string message)
	{
		double x;
		cin >> x;

		while (x < from || x > to)
		{
			cout << message;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> x;
		}
		return x;
	}

	static bool IsValidDate(clsDate date)
	{
		return clsDate::IsValidDate(date);
	}

	static string ReadString()
	{
		string s;
		getline(cin >> ws , s);
		return s;
	}

	static char Readchar()
	{
		char c;
		cin >> c;
		return c;
	}


};
