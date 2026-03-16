#pragma once
#include <iostream>
#include <vector>
using namespace std;

class clsString
{
	string _UserString;

	char readletter()
	{
		char letter;
		cout << "Enter the letter you want to count : ";
		cin >> letter;
		return letter;
	}


public:

	//constructor
	clsString()
	{
	}
	clsString(string UserString)
	{
		_UserString = UserString;
	}

	static short Length(string S1)
	{
		return S1.length();
	};

	short Length()
	{
		return _UserString.length();
	};



	static string printcapitalfirstletter(string sentence)
    {
	   bool isfirst = true;

	   for (int i = 0; i < sentence.length(); i++)
	   {
		   if (isfirst && isalpha(sentence[i]))
		   {
			   sentence[i] = toupper(sentence[i]);
			   isfirst = false;
		   }
		   else if (sentence[i] == ' ')
		   {
			   isfirst = true;
		   }
	   }
	   return sentence;
	}
	
    string printcapitalfirstletter()
	{
		return printcapitalfirstletter(_UserString);
	}

	static string printcapitalletters(string sentence)
    {
	    for (int i = 0; i < sentence.length(); i++)
	    {
			sentence[i] = toupper(sentence[i]);
	    }
		return sentence;
    }
    
	string printcapitalletters()
	{
		return printcapitalletters(_UserString);
	}

    string printlowerletters(string sentence)
    {
	    for (int i = 0; i < sentence.length(); i++)
	    {
		sentence[i] = tolower(sentence[i]);
	    }
	    return sentence;
    }
	string printlowerletters()
	{
		return printlowerletters(_UserString);
	}

	void countcapitalorlowerletters(string message)
	{
		int counter1 = 0;
		int counter2 = 0;
		for (int i = 0; i < message.length(); i++)
		{
			if (isupper(message[i]) && isalpha(message[i]))
				counter1++;
			else if (islower(message[i]) && isalpha(message[i]))
				counter2++;
			else
				continue;
		}
		cout << "string length = " << message.length() << endl;
		cout << "Capital letters count = " << counter1 << endl;
		cout << "Small letters count = " << counter2 << endl;
	}
	void countcapitalorlowerletters()
	{
		countcapitalorlowerletters(_UserString);
	}

    void countletter(string sentence)
	{
		char letter = readletter();
		int counter = 0;
		for (int i = 0; i < sentence.length(); i++)
		{
			if (sentence[i] == letter)
				counter++;
		}
		printf("Letter '%*c' count = %d", 1, letter, counter);
	}

	void countletter()
	{
		countletter(_UserString);
	}

    

	static int countsentence(string s)
	{
		short pos = 0;
		int counter = 0;
		string sWord;
		while ((pos = s.find(" ")) != std::string::npos)
		{
			sWord = s.substr(0, pos);
			if (sWord != "")
			{
				counter++;
			}
			s.erase(0, pos + 1);
		}
		if (s != "")
		{
			counter++;
		}

		return counter;
	}
	int countsentence()
	{
		return countsentence(_UserString);
	}

	string trimleft(string s)
    {
	   int i = 0;
	   while (s[i] == ' ')
	   {  
		  i++;
		  s.erase(0, i);

	   }
	   return s;
    }

    string trimright(string s)
    {
        int i = (s.length()) - 1;
	    while (s[i] == ' ')
	    {
		   i--;
		   s.erase(i , (s.length()) - 1);

	    }
	    return s;
    }

    string trim(string s)
    {
	   return trimleft(trimright(s));
    }  

	string trim()
	{
		return trimleft(trimright(_UserString));
	}

	static vector<string> Split(string S1, string Delim = "#//#")
	{

		vector<string> vString;

		short pos = 0;
		string sWord; 


		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);   
			if (sWord != "")
			{
				vString.push_back(sWord);
			}

			S1.erase(0, pos + Delim.length());  
		}

		if (S1 != "")
		{
			vString.push_back(S1); 
		}

		return vString;

	}

	vector<string> Split(string Delim = "#//#")
	{
		return Split(_UserString, Delim);
	}

	static string JoinString(vector<string> vString, string Delim)
	{

		string S1 = "";

		for (string& s : vString)
		{
			S1 = S1 + s + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());


	}

	void SetUserString(string userstring)
	{
		_UserString = userstring;
	}

	string GetUserString()
	{
		return _UserString;
	}

	__declspec(property(get = GetUserString, put = SetUserString)) string userstring;

};

