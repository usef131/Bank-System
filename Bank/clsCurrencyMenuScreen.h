#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include <iomanip>
#include "clsShowCurrencyList.h"
#include "clsFindCurrency.h"
#include "clsUpdateCurrencyRate.h"
#include "clsCureencyCalc.h"

class clsCurrencyMenuScreen : protected clsScreen
{

    enum enCurrencyMenueOptions {
        eListCurrency = 1, eFindCurrency = 2,
        eUpdateCurrency = 3, eCurrencyCalc = 4, eMainMenue = 5
    };

    static short _ReadCurrencyMenueOption()
    {
        short x = clsInputValidate::ReadIntNumberbetween(1, 5, "\t\t\t\t\tEnter Number between 1 to 5? ");
        return x;
    }

    static void _GoBackToCurrencyMenue()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0");
        ShowCurrencyMenue();
    }


    static void _ShowListCurrencyScreen()
    {
        clsShowCurrencyList::ShowAllCurrenciesList();
    }

    static void _FindCurrencyScreen()
    {
        clsFindCurrency::FindCurrency();
    }

    static void _UpdateRateScreen()
    {
        clsUpdateCurrencyRate::UpdateCurrency();
    }

    static void _CurrencyCalcScreen()
    {
        clsCureencyCalc::CurrencyCalaulator();
    }



    static void _PerformCurrencyMenueOption(enCurrencyMenueOptions CurrencyMenuOption)
    {
        switch (CurrencyMenuOption)
        {
        case enCurrencyMenueOptions::eListCurrency:
             system("cls");
            _ShowListCurrencyScreen();
            _GoBackToCurrencyMenue();
            break;
        case enCurrencyMenueOptions::eFindCurrency:
            system("cls");
            _FindCurrencyScreen();
            _GoBackToCurrencyMenue();
            break;
        case enCurrencyMenueOptions::eUpdateCurrency:
            system("cls");
            _UpdateRateScreen();
            _GoBackToCurrencyMenue();
            break;
        case enCurrencyMenueOptions::eCurrencyCalc:
            system("cls");
            _CurrencyCalcScreen();
            _GoBackToCurrencyMenue();
            break;
        case enCurrencyMenueOptions::eMainMenue:
        {
        
        }     
        }
    }

public:
    static void ShowCurrencyMenue()
    {
        if (!AccesssRights(clsUser::enPermissions::pManageUsers))
            return;

        system("cls");
        _PrintTitleofPage("Currency Exhange Main Screen");


        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyMenueOption((enCurrencyMenueOptions)_ReadCurrencyMenueOption());
    }
};

