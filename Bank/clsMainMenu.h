#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClient.h"
#include "clsDeleteClient.h"
#include "clsUpdateClient.h"
#include "clsFindClient.h"
#include "clsTransactionsScreen.h"
#include "clsMangeUsersScreen.h"
#include "Globle.h"
#include "clsLoginScreen.h"
#include "clsLoginRegister.h"
#include "clsCurrencyMenuScreen.h"
using namespace std;

class clsMainMenu :protected clsScreen
{
    enum enMainMenuOptions{
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, enloginregister = 8 , eCurrency = 9  , eExit = 10
    };

    static int _ReadMainMenuChoice()
    {
        return clsInputValidate::ReadIntNumberbetween(1, 10, "\t\t\t\t\tPlease Enter Number Between 1 to 10 : ");
    }

    static void _GoBackToMainMenu()
    {
        cout << setw(37) << left << "" << "\nPress any key to Go to Main Menu";
        system("Pause>0");
        ShowMainMenu();
    }

    static void _Showclientslist()
    {
        clsClientListScreen::ShowallClientsList();
    }
    
    static void _AddClient()
    {
        clsAddNewClient::AddNewClient();
    }

    static void _DeleteClient()
    {

        clsDeleteClient::DeleteCLient();
    }

    static void _UpdateClient()
    {

        clsUpdateClient::UpdateClient();
    }

    static void _FindClient()
    {
  
        clsFindClient::FindClinet();
    }

    static void _Transactions()
    {
   
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _MangeUsers()
    {
        clsMangeUsersScreen::ShowMangeUsersMenue();
    }

    static void _LoginRegister()
    {
        clsLoginRegister::showLoinRegister();
    }
    
    static void _CurrencyMainScreen()
    {
        clsCurrencyMenuScreen::ShowCurrencyMenue();
    }

    static void _Logout()
    {
       CurrentUser = clsUser::Find(" " , " ");
    }

    static void _AfterSelectchoice(enMainMenuOptions selectedop)
    {
        system("cls");
        switch (selectedop)
        {
        case enMainMenuOptions::eListClients:
            _Showclientslist();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eAddNewClient:
            _AddClient();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eDeleteClient:
            _DeleteClient();
            _GoBackToMainMenu();
            break;
        case enMainMenuOptions::eUpdateClient:
            _UpdateClient();
            _GoBackToMainMenu();
            break;
        case enMainMenuOptions::eFindClient:
            _FindClient();
            _GoBackToMainMenu();
            break;
        case enMainMenuOptions::eShowTransactionsMenue:
            _Transactions();
            _GoBackToMainMenu();
            break;
        case enMainMenuOptions::eManageUsers:
            _MangeUsers();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::enloginregister:
            _LoginRegister();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eCurrency:
            _CurrencyMainScreen();
            _GoBackToMainMenu();
            break;
        case enMainMenuOptions::eExit:
            _Logout();
            break;

        }
    }

public:

    static void ShowMainMenu()
    {
        system("cls");
        _PrintTitleofPage("\tMain Screen");
       
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _AfterSelectchoice((enMainMenuOptions)_ReadMainMenuChoice());
    }

};

