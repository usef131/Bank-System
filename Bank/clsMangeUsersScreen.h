#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsListUsersScreen.h"
#include "clsAddNewUser.h"
#include "clsDeleteUser.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUser.h"
#include "clsUser.h"
using namespace std;

class clsMangeUsersScreen : protected clsScreen
{
    enum enManageUsersMenueOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };

    static short _ReadMangeUsersMenueOption()
    {
        short x = clsInputValidate::ReadIntNumberbetween(1, 6, "\t\t\t\t\tEnter Number between 1 to 6? ");
        return x; 
    }

    static void _GoBackToManageUsersMenue()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0");
        ShowMangeUsersMenue();
    }

    static void _ShowListUsersScreen()
    { 
        clsListUsersScreen::ShowallUsersList();
    }

    static void _ShowAddNewUserScreen()
    {
        clsAddNewUser::AddNewUserscreen();

    }

    static void _ShowDeleteUserScreen()
    {
        clsDeleteUser::DeleteUser();

    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        clsFindUser::ShowFindUserScreen();
    }

    static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
    {
        switch (ManageUsersMenueOption)
        {
        case clsMangeUsersScreen::eListUsers:
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenue();
            break;
        case clsMangeUsersScreen::eAddNewUser:
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;
        case clsMangeUsersScreen::eDeleteUser:
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;
        case clsMangeUsersScreen::eUpdateUser:
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenue();
            break;
        case clsMangeUsersScreen::eFindUser:
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;
        case clsMangeUsersScreen::eMainMenue:
            break;
    
        }
    }


public:
    static void ShowMangeUsersMenue()
    {
        if (!AccesssRights(clsUser::enPermissions::pManageUsers))
            return;

        system("cls");
        _PrintTitleofPage("  Mange Users Screen");
      

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersMenueOption((enManageUsersMenueOptions)_ReadMangeUsersMenueOption());
    }

};

