#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsAddNewUser : public clsScreen
{

	static void _ReadUserInfo(clsUser &user)
	{
		cout << "\nPlease Enter your First Name : ";
		user.FirstName = clsInputValidate::ReadString();

		cout << "\nPlease Enter your Last Name : ";
		user.LastName = clsInputValidate::ReadString();

		cout << "\nPlease Enter your Email : ";
		user.Email = clsInputValidate::ReadString();

		cout << "\nPlease Enter your Phone : ";
		user.Phone = clsInputValidate::ReadString();

		cout << "\nPlease Enter your Password : ";
		user.Password = clsInputValidate::ReadString();

		cout << "\nPlease Enter your Permissions : ";
        user.Permissions = _GetPermissionsToUser();
	}
	static void _PrintUserCard(clsUser user)
	{
		cout << "\nClient Card:";
		cout << "\n______________________________";
		cout << "\nFirstName   : " << user.FirstName;
		cout << "\nLastName    : " << user.LastName;
		cout << "\nFull Name   : " << user.FullName();
		cout << "\nEmail       : " << user.Email;
		cout << "\nPhone       : " << user.Phone;
		cout << "\nPassword    : " << user.Password;
		cout << "\nPermissions : " << user.Permissions;
		cout << "\n_____________________________\n\n";
	}

	static int _GetPermissionsToUser()
	{
		int Permissions = 0;
		char Answer = 'y';

        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        cout << "\nLogin Register? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pLoginRegister;
        }

        return Permissions;
	}

public:

    static void AddNewUserscreen()
    {
        _PrintTitleofPage("  Add New User Screen");
 

        cout << "Enter User Name to Add : ";
        string username = clsInputValidate::ReadString();

        while (clsUser::IsUserExist(username))
        {
            cout << "\nUserName Is Already Used, Choose another one: ";
            username = clsInputValidate::ReadString();
        }


        clsUser NewUser = clsUser::Addnewuser(username);
        _ReadUserInfo(NewUser);

        clsUser::enSaveMode savemode;

        savemode = NewUser.Save();

        switch (savemode)
        {
        case clsUser::svSuccessfull:
            cout << "\n\nNew User Added Successfully...";
            _PrintUserCard(NewUser);
            break;
        case clsUser::svFaild:
            cout << "\nError User was not saved because it's Empty";
            break;
        case clsUser::svFaildUserExists:
            cout << "\nError User was not saved because UserName is used!\n";
            break; 
        }


    }



};

