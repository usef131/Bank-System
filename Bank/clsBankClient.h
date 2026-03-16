#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsUtility.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;
class clsBankClient : public clsPerson
{
	enum enMode {enEmpty = 0 , enUpdate = 1 , enAddNew = 2};


	struct stTransferLog;

	string _PinCode;
	string _AccountNumber;
	long long _AccountBalance;
	bool _DeleteMark = false;
	enMode _Mode;

	static clsBankClient _ConvertLinetoobjectclient(string line , string delmi = "#//#")
	{
		vector<string> vclient = clsString::Split(line, delmi);

		return clsBankClient(enMode::enUpdate, vclient[0], vclient[1], vclient[2], vclient[3], 
			   vclient[4], clsUtility::Decryption(vclient[5] , 3), stol(vclient[6]));
	}

	static stTransferLog _ConvertLinetoObjectTransferLog(string line, string delmi = "#//#")
	{
		vector<string> vTransfer = clsString::Split(line, delmi);
		stTransferLog OP;

		OP.DateandTime = vTransfer[0];
		OP.sourceAccount = vTransfer[1];
		OP.DilverdAccount = vTransfer[2];
		OP.Amount = stod(vTransfer[3]);
		OP.SourceBalance = stod(vTransfer[4]);
		OP.DilverdBalance= stod(vTransfer[5]);
		OP.User = vTransfer[6];

		return OP;
	}


	static clsBankClient _EmptyClientObject()
	{
		return clsBankClient(enMode::enEmpty, "", "", "", "", "", "", 0);
	}

	static vector<clsBankClient> _SaveAllClientsDatafromFiletoVector()
	{
		vector<clsBankClient> vClients;
		fstream myfile;
		myfile.open("Clients.txt", ios::in);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsBankClient client = _ConvertLinetoobjectclient(line);
				vClients.push_back(client);
			}
			myfile.close();
		}
		return vClients;
	}

	static string _ConvertObjectToOneLineString(clsBankClient client , string delmi = "#//#")
	{
		string s = "";

		s += client.FirstName + delmi;
		s += client.LastName + delmi;
		s += client.Email + delmi;
		s += client.Phone + delmi;
		s += client.AccountNumber() + delmi;
		s += clsUtility::encryption(client.PinCode , 3) + delmi;
		s += to_string(client.AccountBalance) ;

		return s;
	}

	string _ConvertObjectToOneLineForTransfer(clsBankClient client , double Amount , string delmi = "#//#")
	{
		string s = "";

		s += clsDate::printdateandtime(clsDate()) + delmi;
		s += this->AccountNumber() + delmi;
		s += client.AccountNumber() + delmi;
		s += to_string(Amount) + delmi;
		s += to_string(this->AccountBalance) + delmi;
		s += to_string(client.AccountBalance) + delmi;
		s += CurrentUser.UserName;

		return s;
	}

	static void LoadDatataToTransferFile(string line)
	{
		fstream myfile;
		myfile.open("TransferLog.txt", ios::out | ios::app);
		if (myfile.is_open())
		{
			myfile << line << endl;
			myfile.close();
		}
	}

	static void LoadDatataTofile(string line)
	{
		fstream myfile;
		myfile.open("Clients.txt", ios::out | ios::app);
		if (myfile.is_open())
		{
			myfile << line << endl;
			myfile.close();
		}
	}

	static void _SaveDataFromVectorToFile(vector<clsBankClient> vclients)
	{
		fstream myfile;
		myfile.open("Clients.txt", ios::out);
		if (myfile.is_open())
		{
			for (clsBankClient& client : vclients)
			{

				if (client.GetDeletedMarked() == false)
				{
					string line = _ConvertObjectToOneLineString(client);
					myfile << line << endl;
				}
				else
					continue;
			}
			myfile.close();
		}
	}

	void _update()
	{
		vector<clsBankClient> vCLients = _SaveAllClientsDatafromFiletoVector();

		for (clsBankClient& client : vCLients)
		{
			if (client.AccountNumber() == AccountNumber())
			{
				client = *this;
			}
		}
		_SaveDataFromVectorToFile(vCLients);
	}

	void _AddNew()
	{
		LoadDatataTofile(_ConvertObjectToOneLineString(*this));
	}

public:

	clsBankClient(enMode mode, string firstname, string lastname, string gmail, string phone
		, string accountnumber, string pincode, long long accountbalance)
		: clsPerson(firstname, lastname, gmail, phone)
	{
		_Mode = mode;
		_AccountNumber = accountnumber; 
		_AccountBalance = accountbalance;
		_PinCode = pincode;
	}

	struct stTransferLog
	{
		string DateandTime;
		string sourceAccount;
		string DilverdAccount;
		double Amount;
		double SourceBalance;
		double DilverdBalance;
		string User;
	};


	bool IsclientEmpty()
	{
		return (_Mode == enMode::enEmpty);
	}

    bool GetDeletedMarked()
	{
		return _DeleteMark;
 	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(long long AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";
	}

	static clsBankClient Find(string AccountNumber)
	{
		fstream myfile;
		myfile.open("Clients.txt", ios::in);

		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{

				clsBankClient client = clsBankClient::_ConvertLinetoobjectclient(line);
				if (client.AccountNumber() == AccountNumber)
				{
					myfile.close();
					return client;
				}
			}
		}
		return clsBankClient::_EmptyClientObject();	
	}

	static clsBankClient Find(string AccountNumber , string pincode)
	{
		fstream myfile;
		myfile.open("Clients.txt", ios::in);

		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{

				clsBankClient client = clsBankClient::_ConvertLinetoobjectclient(line);
				if (client.AccountNumber() == AccountNumber && client.GetPinCode() == pincode)
				{
					myfile.close();
					return client;
				}
			}
		}
		return clsBankClient::_EmptyClientObject();
	}

	static bool IsclientExist(string AccountNumber)
	{
		clsBankClient client = clsBankClient::Find(AccountNumber);
		return (!(client.IsclientEmpty()));
	}

	enum enSaveResults { svFaild = 0, svSuccessed = 1, svFaildAccountNumberExists = 2 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::enEmpty:

			return enSaveResults::svFaild;
			break;

		case enMode::enUpdate:

			_update();
			return enSaveResults::svSuccessed;
			break;

		case enMode::enAddNew:

			if (clsBankClient::IsclientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::enUpdate;
				return enSaveResults::svSuccessed;
			}
			break;
		}
	}




	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::enAddNew, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector<clsBankClient> vclients = _SaveAllClientsDatafromFiletoVector();

		for (clsBankClient& client : vclients)
		{

			if(client.AccountNumber() == AccountNumber())
			{
				client._DeleteMark = true;
				break;
			}

		}
		_SaveDataFromVectorToFile(vclients);
		*this = _EmptyClientObject();
		return true;

	}

	static vector<clsBankClient> ShowClientsList()
	{
		return _SaveAllClientsDatafromFiletoVector();
	}
    

	void Deposit(double number)
	{
		_AccountBalance += number;
		Save();
	}

	bool WithDraw(double number)
	{
		if (number > _AccountBalance)
		{
			return false;
		}
		_AccountBalance -= number;
		Save();
		return true;
	}

	static long long SumofAllBalacnes()
	{
		vector<clsBankClient> vclients = _SaveAllClientsDatafromFiletoVector();

		long long Sum = 0;

		for (clsBankClient& client : vclients)
		{
			Sum += client.AccountBalance;
		}
		cout << endl;
		return Sum;
	}

	void TransferLog(double Amount , clsBankClient DeliveredClient , string UserName)
	{

	}


    void Transfermoneyto(clsBankClient &client2 , double Amount)
	{
		WithDraw(Amount);
		client2.Deposit(Amount);

		LoadDatataToTransferFile(_ConvertObjectToOneLineForTransfer(client2, Amount));

	}

	static vector<stTransferLog> SaveAllTransfer()
	{
		vector<stTransferLog> vTransfer;
		fstream myfile;
		myfile.open("TransferLog.txt", ios::in);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				stTransferLog OP = _ConvertLinetoObjectTransferLog(line);
				vTransfer.push_back(OP);
			}
			myfile.close();
		}
		return vTransfer;
	}


};

