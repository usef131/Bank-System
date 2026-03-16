#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <string>
#include "clsUser.h"

class clsDeleteClient : protected clsScreen
{
private:

    static void _PrintClientCard(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n______________________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n_____________________________\n\n";
    }

public :
    static void DeleteCLient()
    {

        if (!AccesssRights(clsUser::enPermissions::pDeleteClient))
            return;


        _PrintTitleofPage("Delete Client Screen");



        string AccountNumber;
        cout << "Please Enter Account Number That you want to Delete: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!(clsBankClient::IsclientExist(AccountNumber)))
        {
            cout << "\nThis Account number is not Exist, Enter Account number: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClientCard(Client);

        cout << "\n--------------------------\n";

        char userans;
        cout << "\nAre you sure that you want to delete this account (Y|N): ";
        userans = clsInputValidate::Readchar();

        if (userans == 'y' || userans == 'Y')
        {

            if (Client.Delete())
            {
                cout << "\nThis Account Has been deleted successfully :)";
                _PrintClientCard(Client);
            }
            else
                cout << "\nThis Account Has not been deleted :(";
        }
        else
        {
            cout << "\n OK, Thank you for using this program ;)\n";
        }
    }


};

