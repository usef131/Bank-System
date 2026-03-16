#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsUtility.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class clsUser : public clsPerson
{
private:

	enum enModes { enEmpty, enUpdate, enAddNew};

	enModes _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _DeleteFlag = false;





	static clsUser _ConvertLineToObjectUser(string line, string delmi = "#//#")
	{
		vector<string> vUser = clsString::Split(line, delmi);

		return clsUser(enModes::enUpdate, vUser[0], vUser[1], vUser[2], vUser[3],
			vUser[4], clsUtility::Decryption(vUser[5] ,3) , stoi(vUser[6]));
	}


	static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
	{

		string UserRecord = "";
		UserRecord += User.FirstName + Seperator;
		UserRecord += User.LastName + Seperator;
		UserRecord += User.Email + Seperator;
		UserRecord += User.Phone + Seperator;
		UserRecord += User.UserName + Seperator;
		UserRecord += clsUtility::encryption(User.Password , 3) + Seperator;
		UserRecord += to_string(User.Permissions);

		return UserRecord;

	}

	static string _ConverUserObjectToRecordinloginfile(clsUser User , string Seperator = "#//#")
	{

		string LoginRecord = "";
		LoginRecord += clsDate::DatetoString(clsDate()) + " - ";
		LoginRecord += clsDate::PrintCurrentTime() + Seperator;
		LoginRecord += User.UserName + Seperator;
		LoginRecord += clsUtility::encryption(User.Password, 3) + Seperator;
		LoginRecord += to_string(User.Permissions);

		return LoginRecord;
	}

	static void _AddDataLineToLoginfile(string s)
	{
		fstream myfile;
		myfile.open("LoginRegister.txt", ios::out | ios::app);
		if (myfile.is_open())
		{
			myfile << s << endl;
		}
		myfile.close();

	}



	static  vector <clsUser> _LoadUsersDataFromFile()
	{

		vector <clsUser> vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsUser User = _ConvertLineToObjectUser(Line);

				vUsers.push_back(User);
			}

			MyFile.close();

		}

		return vUsers;

	}

	static void _SaveUsersDataToFile(vector <clsUser> vUsers)
	{

		fstream MyFile;
		MyFile.open("Users.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsUser &U : vUsers)
			{
				if (U.MarkedForDeleted() == false)
				{
					//we only write records that are not marked for delete.  
					DataLine = _ConverUserObjectToLine(U);
					MyFile << DataLine << endl;

				}

			}

			MyFile.close();

		}

	}

	static void _AddDataLineToFile(string s)
	{
		fstream myfile;
		myfile.open("Users.txt" , ios::out | ios::app);
		if (myfile.is_open())
		{
			myfile << s << endl;
		}
		myfile.close();

	}


	void _Update()
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : _vUsers)
		{
			if (U.UserName == UserName)
			{
				U = *this;
				break;
			}

		}
		_SaveUsersDataToFile(_vUsers);

	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConverUserObjectToLine(*this));
	}

	static clsUser _EmptyUserObject()
	{
		return clsUser(enModes::enEmpty, "", "", "", "", "", "", 0);
	}
	struct stLoginRegister;

	static stLoginRegister _convertLoginRecordtoinfo(string line, string delmi = "#//#")
	{
		stLoginRegister user;
		vector<string> myvector = clsString::Split(line, delmi);

		user.Dateandtime = myvector[0];
		user.username = myvector[1];
		user.password = clsUtility::Decryption(myvector[2] , 3);
		user.permissions = stoi(myvector[3]);

		return user;
	}


public:

	struct stLoginRegister
	{
		string Dateandtime;
		string username;
		string password;
		int permissions;
	};



	clsUser(enModes Mode, string firstname, string lastname, string email, string phone
		, string username, string password, int permissions) : clsPerson(firstname, lastname, email, phone)
	{
		_Mode = Mode;
		_UserName = username;
		_Password = password;
		_Permissions = permissions;
	}

	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64 , pLoginRegister = 128
	};

    bool MarkedForDeleted()
	{
		return _DeleteFlag;
	}

	bool IsEmpty()
	{
		return (enModes::enEmpty == _Mode);
	}


	void setUserName(string username)
	{
		_UserName = username;
	}

	string GetUsername()
	{
		return _UserName;
	}

	__declspec(property(get = GetUsername, put = setUserName)) string UserName;

	void setPassword(string pass)
	{
		_Password = pass;
	}

	string GetPassword()
	{
		return _Password;
	}

	__declspec(property(get = GetPassword, put = setPassword)) string Password;


	void setPermission(int permission)
	{
		_Permissions = permission;
	}

	int GetPermission()
	{
		return _Permissions;
	}
	__declspec(property(get = GetPermission, put = setPermission)) int Permissions;



	static clsUser Find(string username)
	{
		fstream myfile;
		myfile.open("Users.txt", ios::in);

		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{

				clsUser user = clsUser::_ConvertLineToObjectUser(line);
				if (user.UserName == username)
				{
					return user;
				}
			}
		myfile.close();
		}
		return clsUser::_EmptyUserObject();
	}

	static clsUser Find(string username, string password)
	{
		fstream myfile;
		myfile.open("Users.txt", ios::in);

		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{

				clsUser user = clsUser::_ConvertLineToObjectUser(line);
				if (user.UserName == username && user.Password  == password)
				{
					return user;
				}
			}
		myfile.close();
		}
		return clsUser::_EmptyUserObject();
	}

	static bool IsUserExist(string username)
	{
		clsUser user = clsUser::Find(username);

		return (!user.IsEmpty());
	}

	enum enSaveMode {svSuccessfull  , svFaild , svFaildUserExists};



	enSaveMode Save()
	{
		switch (_Mode)
		{
		case enModes::enEmpty:

			if (IsEmpty())
			{
				return enSaveMode::svFaild;
			}
			break;

		case enModes::enUpdate:
			_Update();
			return enSaveMode::svSuccessfull;
			break;


		case enModes::enAddNew:

			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveMode::svFaildUserExists;
			}
			else
			{
				_AddNew();
				_Mode = enModes::enUpdate;
				return enSaveMode::svSuccessfull;
				break;
			}
		}
	}


	static clsUser Addnewuser(string username)
	{
		return clsUser(enModes::enAddNew, "", "", "", "", username, "", 0);
	}


	bool Delete()
	{
		vector<clsUser> vUsers = _LoadUsersDataFromFile();

		for (clsUser& user : vUsers)
		{
			if (user.UserName == UserName)
			{
				user._DeleteFlag = true;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
		*this = _EmptyUserObject();
		return true;
	}

	static vector<clsUser> ShowUsersList()
	{
		return  _LoadUsersDataFromFile();
	}


	bool CheckPermission(enPermissions Permission)
	{
		if (this->Permissions == enPermissions::eAll)
			return true;

		if ((Permission & this->Permissions) == Permission)
			return true;
		else
			return false;
	}

	static void saveLoginRegisterinfile(clsUser user)
	{
		_AddDataLineToLoginfile(_ConverUserObjectToRecordinloginfile(user));
	}




	static vector <stLoginRegister> ReadLogininfo()
	{
		vector <stLoginRegister> vLoginUsers;

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;
			while (getline(MyFile, Line))
			{

				stLoginRegister User = _convertLoginRecordtoinfo(Line);

				vLoginUsers.push_back(User);
			}

			MyFile.close();

		}
		return vLoginUsers;
	}



};

