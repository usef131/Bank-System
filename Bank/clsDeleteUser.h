#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include <string>
using namespace std;

class clsDeleteUser : protected clsScreen
{
    static void _PrintUserCard(clsUser user)
    {
        cout << "\nUser Card:";
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

public :
    static void DeleteUser()
    {
        _PrintTitleofPage(" Delete User Screen");


        string UserName;
        cout << "\nPlease Enter User Name That you want to Delete: ";
        UserName = clsInputValidate::ReadString();

        while (!(clsUser::IsUserExist(UserName)))
        {
            cout << "\nThis Account number is not Exist, Enter Account number: ";
            UserName = clsInputValidate::ReadString();
        }

         clsUser user = clsUser::Find(UserName);
        _PrintUserCard(user);

        cout << "\n--------------------------\n";

        char userans;
        cout << "\nAre you sure that you want to delete this account (Y|N): ";
        userans = clsInputValidate::Readchar();

        if (userans == 'y' || userans == 'Y')
        {

            if (user.Delete())
            {
                cout << "\nThis User Has been deleted successfully :)";
                _PrintUserCard(user);
            }
            else
                cout << "\nThis User Has not been deleted :(";
        }
        else
        {
            cout << "\n OK, Thank you for using this program ;)\n";
        }



    }




};

