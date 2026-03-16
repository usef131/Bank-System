#pragma once
#include<iostream>
#include<string>
#include "clsString.h"
#include <vector>
#include <fstream>

class clsCurrency
{
	enum eMode { EmptyMode , UpdateMode};

	eMode _Mode; 
	string _Country; 
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;


	static clsCurrency _EmptyObject()
	{
		return clsCurrency(eMode::EmptyMode, "", "", "", 0);
	}


    static clsCurrency _GetCurrencyInfo(string line,  string delmi = "#//#")
	{
		vector<string> myvector = clsString::Split(line , delmi);

		return clsCurrency(eMode::UpdateMode, myvector[0], myvector[1], myvector[2], stof(myvector[3]));

	}


    static vector<clsCurrency> _LoadAllDataToVector()
	{
		vector<clsCurrency> vCurrencies; 
		fstream myfile;
		myfile.open("Currencies.txt", ios::in);

		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsCurrency currency = _GetCurrencyInfo(line);
				vCurrencies.push_back(currency);
			}

			myfile.close();
		}

		return vCurrencies;
	}

	string _ConvertToLine(clsCurrency Currency , string Seperator = "#//#")
	{
		string s = "";

		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.Country() + Seperator;
		stCurrencyRecord += Currency.CurrencyCode() + Seperator;
		stCurrencyRecord += Currency.CurrencyName() + Seperator;
		stCurrencyRecord += to_string(Currency.Rate());

		return stCurrencyRecord;
	}

	void _LoadDataToFile(vector<clsCurrency> vCurrency)
	{
		fstream myfile;
		myfile.open("Currencies.txt", ios::out);

		if (myfile.is_open())
		{
			for (clsCurrency& curr : vCurrency)
			{
				string line = _ConvertToLine(curr);
				myfile << line << endl;
			}

			myfile.close();
		}

	}

	void _Update()
	{
		vector <clsCurrency> _vCurrencys;
		_vCurrencys = _LoadAllDataToVector();

		for (clsCurrency& C : _vCurrencys)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}

		}

		_LoadDataToFile(_vCurrencys);

	}





public:


	clsCurrency(eMode mode, string country, string currencycode, string currencyname, float rate)
	{
		_Mode = mode;
		_Country = country;
		_CurrencyCode = currencycode;
		_CurrencyName = currencyname;
		_Rate = rate;
	}

	static vector <clsCurrency> GetAllUSDRates()
	{

		return _LoadAllDataToVector();

	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	float Rate()
	{
		return _Rate;
	}

	bool IsEmpty()
	{
		return (_Mode == eMode::EmptyMode);
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::printcapitalletters(CurrencyCode);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _GetCurrencyInfo(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();

		}
		return _EmptyObject();
	}


	static   clsCurrency FindByCountry(string Country)
	{
		Country = clsString::printcapitalletters(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _GetCurrencyInfo(Line);
				if (clsString::printcapitalletters(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}

			}

			MyFile.close();

		}

		return _EmptyObject();
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}


	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return (!Currency.IsEmpty());
	}

	static vector<clsCurrency> GetCurrencyList()
	{
		return _LoadAllDataToVector();
	}

	float  CovertToUSD(float amount)
	{
		return  (float)(amount / Rate());
	}
	
	float ConverttoOtherCurrency(clsCurrency cuurency2, float amount)
	{
		float USD_Amount = CovertToUSD(amount);

		if (cuurency2.CurrencyCode() == "USD")
		{
			return USD_Amount;
		}
		else
		{
			return (float) USD_Amount * cuurency2.Rate();
		}

	}

};

