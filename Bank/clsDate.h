#pragma once
#pragma warning(disable : 4996)
#include "clsString.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;


class clsDate
{
	int _Day;
	int _Month;
	int _Year;



public:

	clsDate()
	{
		time_t t = time(0);

		tm* now = localtime(&t);

		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;

	}

	clsDate(int day, int month, int year)
	{
		_Day = day;
		_Month = month;
		_Year = year;
	}



	clsDate(string date)
	{
		vector<string> mydate;
		mydate = clsString::Split(date , "/");

		_Day = stoi(mydate[0]);
		_Month = stoi(mydate[1]);
		_Year = stoi(mydate[2]);

	}

	void SetDay(short Day) {
		_Day = Day;
	}

	short GetDay() {
		return _Day;
	}
	__declspec(property(get = GetDay, put = SetDay)) short Day;

	void SetMonth(short Month) {
		_Month = Month;
	}

	short GetMonth() {
		return _Month;
	}
	__declspec(property(get = GetMonth, put = SetMonth)) short Month;


	void SetYear(short Year) {
		_Year = Year;
	}

	short GetYear() {
		return _Year;
	}
	__declspec(property(get = GetYear, put = SetYear)) short Year;


	static clsDate GetSystemDate()
	{
		//system date
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;

		return clsDate(Day, Month, Year);
	}

	static bool isyearleap(int year)
	{
		return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
	}

	bool isyearleap()
	{
		return isyearleap(_Year);
	}

	static short daysofmonth(clsDate date)
	{

		bool check = isyearleap(date.Year);
		short arr[] = { 31 , 28 , 31 , 30 , 31 , 30 , 31, 31 , 30 , 31, 30 , 31 };
		return (date.Month == 2) ? ((check) ? 29 : 28) : arr[date.Month - 1];
	}

	short daysofmonth(int mon)
	{

		bool check = isyearleap();
		short arr[] = { 31 , 28 , 31 , 30 , 31 , 30 , 31, 31 , 30 , 31, 30 , 31 };
		return (mon == 2) ? ((check) ? 29 : 28) : arr[mon - 1];
	}

	short daysofmonth()
	{
		bool check = isyearleap();
		short arr[] = { 31 , 28 , 31 , 30 , 31 , 30 , 31, 31 , 30 , 31, 30 , 31 };
		return (_Month == 2) ? ((check) ? 29 : 28) : arr[_Month - 1];
	}
	static bool Isvaliddayinmonth(clsDate date)
	{
		return (date.Day > daysofmonth(date)) ? false : true;
	}

	bool Isvaliddayinmonth()
	{
		return (_Day > daysofmonth()) ? false : true;
	}

	static bool IsvalidMonth(int month)
	{
		return (month > 12 || month < 1) ? false : true;
	}

	bool IsvalidMonth()
	{
		return (_Month > 12 || _Month < 1) ? false : true;
	}

	static bool IsValidDate(clsDate date)
	{
		return (Isvaliddayinmonth(date) && IsvalidMonth(date.Month));
	}

	bool IsValidDate()
	{
		return (Isvaliddayinmonth() && IsvalidMonth());
	}

	clsDate(int orderofday, int year)
	{
		short mon = 1;
		bool check = isyearleap();
		int numberofday = orderofday;

		while (orderofday > daysofmonth(mon))
		{
			orderofday -= daysofmonth(mon);
			mon++;
			if (mon == 12)
				mon = 1;
		}
		_Day = orderofday;
		_Month = mon;
		_Year = year;
	}

	short calcday(int day = 1)
	{
		short a = (14 - _Month) / 12;
		short y = _Year - a;
		short m = _Month + (12 * a) - 2;

		return  (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short calcday(int year , int month , int day = 1)
	{
		short a = (14 - month) / 12;
		short y = year - a;
		short m = month + (12 * a) - 2;

		return  (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	string printmonthName()
	{
		string arr[] = { "" , "Jan" , "Feb" , "Mar" , "Apr" , "May" , "Jun" , "Jul" ,"Aug" , "Sep" , "Oct" , "Nov" , "Dec" };
		return arr[_Month];
	}
	string printmonthName(int month)
	{
		string arr[] = { "" , "Jan" , "Feb" , "Mar" , "Apr" , "May" , "Jun" , "Jul" ,"Aug" , "Sep" , "Oct" , "Nov" , "Dec" };
		return arr[month];
	}

	void printMonthcalender(int mon)
	{
		string month = printmonthName(mon);
		short dayorder = calcday(_Year , mon);
		int dayofmonth = daysofmonth(mon);

		cout << "\n   __________________" + month + "__________________\n\n";


		cout << setw(6) << "Sun";
		cout << setw(6) << "Mon";
		cout << setw(6) << "Tue";
		cout << setw(6) << "Wed";
		cout << setw(6) << "Thu";
		cout << setw(6) << "Fri";
		cout << setw(6) << "Sat";
		cout << endl;

		int counter = 0;

		for (int i = 0; i < dayorder; i++)
		{
			cout << setw(6) << " ";
			counter++;
		}

		for (int j = 1; j <= dayofmonth; j++)
		{
			cout << setw(6) << j;
			counter++;
			if (counter == 7)
			{
				cout << endl;
				counter = 0;
			}
		}
		cout << "\n   _______________________________________\n\n";


	}

	void printMonthcalender()
	{
		string month = printmonthName();
		short dayorder = calcday();
		int dayofmonth = daysofmonth();

		cout << "\n   __________________" + month + "__________________\n\n";


		cout << setw(6) << "Sun";
		cout << setw(6) << "Mon";
		cout << setw(6) << "Tue";
		cout << setw(6) << "Wed";
		cout << setw(6) << "Thu";
		cout << setw(6) << "Fri";
		cout << setw(6) << "Sat";
		cout << endl;

		int counter = 0;

		for (int i = 0; i < dayorder; i++)
		{
			cout << setw(6) << " ";
			counter++;
		}

		for (int j = 1; j <= dayofmonth; j++)
		{
			cout << setw(6) << j;
			counter++;
			if (counter == 7)
			{
				cout << endl;
				counter = 0;
			}
		}
		cout << "\n   _______________________________________\n\n";


	}


	void printcalenderofyear()
	{
		cout << "\n _______________________________________\n\n";
		cout << "\t\tCalendar - " << _Year;
		cout << "\n _______________________________________\n\n";

		for (int month = 1; month <= 12; month++)
		{
			printMonthcalender(month);
			cout << endl;
		}
	}

	int calcnumberoftheday()
	{
		int sum = 0;
		bool check = isyearleap();

		for (int mon = 1; mon < _Month; mon++)
		{
			sum = sum + daysofmonth(mon);
		}
		return sum + _Day;
	}


	void dateafteraddingdays(int adddays)
	{
		short mon = 1;
		bool check = isyearleap();
		int numberofdayinyear = calcnumberoftheday();
		numberofdayinyear = numberofdayinyear + adddays;
		int numberofday = numberofdayinyear;

		while (numberofdayinyear > daysofmonth(mon))
		{
			numberofdayinyear -= daysofmonth(mon);
			mon++;

			if (mon == 13)
			{
				mon = 1;
				_Year++;
			}
		}
		cout << endl << "Date for [" << numberofday << "] is : " << numberofdayinyear << "/" << mon << "/" << _Year << endl;
	}

    static bool IsDateonebeforedatetwo(clsDate date1, clsDate date2)
	{

		return (date1._Year < date2._Year) ? true : (date1._Year == date2._Year) ? (date1._Month < date2._Month) ? true : ((date1._Month == date2._Month) ? (date1._Day < date2._Day) : false) : false;

	}

    bool IsDateonebeforedatetwo(clsDate date2)
	{

		return IsDateonebeforedatetwo(*this ,  date2);

	}

	static bool Isdateoneequaldatetwo(clsDate date1, clsDate date2)
	{

		return (date1._Year == date2._Year) ? ((date1._Month == date2._Month) ? (date1._Day == date2._Day) : false) : false;
	}

    bool Isdateoneequaldatetwo(clsDate date2)
	{

		return Isdateoneequaldatetwo(*this  , date2);
	}


	static bool IsDateoneAfterdatetwo(clsDate date1, clsDate date2)
	{
		return (!IsDateonebeforedatetwo(date1, date2) && !Isdateoneequaldatetwo(date1, date2));
	}

    bool IsDateoneAfterdatetwo(clsDate date2)
	{
		return IsDateoneAfterdatetwo(*this ,  date2);
	}

	enum ensdatecheck { After = 1, Equal = 0, Before = -1 };


	static ensdatecheck comparedate(clsDate date1, clsDate date2)
	{
		if (IsDateoneAfterdatetwo(date1, date2))
			return ensdatecheck::After;

		else if (Isdateoneequaldatetwo(date1, date2))
			return ensdatecheck::Equal;

		else
			return ensdatecheck::Before;
	}

	ensdatecheck comparedate(clsDate date2)
	{
		return comparedate(*this ,  date2);
	}

	string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
	{

		short pos = S1.find(StringToReplace);

		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
			pos = S1.find(StringToReplace);
		}

		return S1;

	}

	string Formatedate(clsDate date , string s = "dd/mm/yy")
	{
		string formatdates = ReplaceWordInString(s, "dd", to_string(date._Day));
		formatdates = ReplaceWordInString(formatdates, "mm", to_string(date._Month));
		formatdates = ReplaceWordInString(formatdates, "yy", to_string(date._Year));

		return formatdates;
	}

	static void swapdates(clsDate &date1, clsDate& date2)
	{
		clsDate date3;

		date3._Day = date1._Day;
		date3._Month = date1._Month;
		date3._Year = date1._Year;

		date1._Day = date2._Day;
		date1._Month = date2._Month;
		date1._Year = date2._Year;

		date2._Day = date3._Day;
		date2._Month = date3._Month;
		date2._Year = date3._Year;

	}

    bool isdayislastinmonth(clsDate date)
	{
		bool isleap = isyearleap();

		short daysinmonth = daysofmonth(date._Month);

		return (date._Day == daysinmonth) ? true : false;
	}

	bool ismonthislastinyear(short month)
	{
		return (month == 12) ? true : false;
	}

	clsDate addoneday(clsDate date)
	{
		if (isdayislastinmonth(date))
		{
			if (ismonthislastinyear(date._Month))
			{
				date._Month = 1;
				date._Day = 1;
				date._Year++;
			}
			else
			{
				date._Month++;
				date._Day = 1;

			}
		}
		else
			date._Day++;

		return clsDate(date._Day, date._Month, date._Year);

	}

	void addoneday()
	{
		*this = addoneday(*this);
	}


	int Getdeffriencebetweendates(clsDate date1 , clsDate date2 , bool encludeendday = false)
	{
		int days = 0;
		short flag = 1;

		if (!IsDateonebeforedatetwo(date1, date2))
		{
			swapdates(date1, date2);
			flag = -1;
		}

		while (IsDateonebeforedatetwo(date1, date2))
		{
			days++;
			date1 = addoneday(date1);
		}
		return  (encludeendday == false) ? days * flag  :  ++days * flag ;
	}

	int Getdeffriencebetweendates(clsDate date2, bool encludeendday = false)
	{
		return Getdeffriencebetweendates(*this, date2);
	}

	static short CalculateMyAgeInDays(clsDate DateOfBirth)
	{
		clsDate date;
		return date.Getdeffriencebetweendates(DateOfBirth, clsDate::GetSystemDate(), true);
	}



    static string DatetoString(clsDate Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

	void DatetoString()
	{
		cout << _Day << "/" << _Month << "/" << _Year << endl;
	}


	static string PrintCurrentTime()
	{
		time_t t = time(0);

		tm* now = localtime(&t);

		return to_string(now->tm_hour) + ":" + to_string(now->tm_min) + ":" + to_string(now->tm_sec);
	}


	static string printdateandtime(clsDate Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year) + " - " + PrintCurrentTime();
	}
};

