#pragma once
#include <cstdlib>
#include <iostream>
#include "clsDate.h"
using namespace std;


class clsUtility
{
public: 

   enum enchartype{ small = 1 , capital  , specialchar , digit , Mix };

   static void Srand()
   {
       srand((unsigned)time(NULL));
   }

   static int RandomNum(int from, int to)
   {
       int randomnumber = rand() % (to - from + 1) + from;
      return randomnumber;
   }


   static char ChooseCharRandomly(enchartype chartype)
   {
        
        switch (chartype)
        {
        case enchartype::small:
            return char(RandomNum(97, 122));
              break;

        case enchartype::capital:
            return char(RandomNum(65, 90));
              break;

        case enchartype::specialchar:
            return char(RandomNum(33, 47));
              break;
        case enchartype::digit:
            return char(RandomNum(48, 57));
              break;

        case  enchartype::Mix:
            short random = RandomNum(1 , 4);
            switch (random)
            {
            case 1:
                return char(RandomNum(65, 90));
                break;

            case 2:
                return char(RandomNum(65, 90));
                break;

            case 3:
                return char(RandomNum(33, 47));
                break;

            case 4:
                return char(RandomNum(48, 57));
                break;
            }
                   
        }
        return '0';
   }

   static string GenerateWord(enchartype chartype , int n)
   {
         string word;
         for (int i = 1; i <= n; i++)
         {
               word = word + ChooseCharRandomly(chartype);
         }
         return word;
   }

   static string generatekey(enchartype chartype)
   {
       string key = "";

       key = GenerateWord(chartype , 4) + "-";
       key = key + GenerateWord(chartype , 4) + "-";
       key = key + GenerateWord(chartype , 4) + "-";
       key = key + GenerateWord(chartype , 4);
       return key;
   }

   static void GenerateKeys(int numberofkeys , enchartype chartype)
   {
       for (int i = 0; i < numberofkeys; i++)
       {
           cout << "key [" << i+1 << "] : ";
           cout << generatekey(chartype) << endl;
       }
   }

   static void swap(int &a , int &b)
   {
         int z ;
         z = a;
         a = b;
         b = z;
   }

   static void swap(string& s1, string& s2)
   {
       string s3;
       s3 = s1;
       s1 = s2;
       s2 = s3;
   }
 
   static void swap(clsDate &date1, clsDate &date2)
   {
       clsDate::swapdates(date1 , date2) ;
   }

   static void shuffle_Array(int array1[100] , int length)
   {
        cout << endl << "Array elments After shuflle: ";
  
        for(int z = 0 ; z < length ; z++)
        {
              swap( array1[RandomNum(0 , length-1)] , array1[RandomNum(0 , length-1)] ) ;
        }
        
        for (int i = 0; i < length; i++)
        {
            cout << array1[i] << " ";
        }

        cout << "\n";
   }
  
   static string encryption(string nam , short enckey)
   {
         for(int i = 0 ; i < nam.length(); i++)
         {
             nam[i] = char((int)nam[i] + enckey);
         }
         return nam;
   }
   
   static string Decryption(string enc , short enckey)
   {
         for(int i = 0 ; i < enc.length(); i++)
         {
             enc[i] = char((int)enc[i] - enckey);
         }
         return enc;
   }

  static void ReadRandomArray(int arr[100], int length)
  {
       for (int i = 0; i <= length - 1; i++)
       {
             arr[i] = RandomNum(1, 100);
       }
  }
 
  static void ReadRandomArray(string arr[100], int numberofkeys , enchartype chartype)
  {
      for (int i = 0; i <= numberofkeys ; i++)
      {
          arr[i] = generatekey(chartype);
      }
  }

  static string Tabs(int num)
  {
      string s; 
      for (int i = 0; i < num; i++)
      {
          s = s + "\t" ;
      }
      return s;
  }

  static string numt_to_text(long long number)
  {
      if (number == 0)
      {
          return "";
      }
      else if (number >= 1 && number <= 19)
      {
          string arr[] = { "" , "One","Two","Three","Four","Five","Six","Seven", "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen", "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

          return arr[number] + " ";


      }
      else if (number >= 20 && number <= 99)
      {
          string arr[] = { "" , "" , "Twenty" , "Thirty" , "Fourthy" , "Fifty" , "Sixty" , "Seventy" , "Eighty" , "Ninety" };
          return arr[number / 10] + " " + numt_to_text(number % 10);
      }

      else if (number >= 100 && number <= 999)
      {
          return  numt_to_text(number / 100) + "Hundred " + numt_to_text(number % 100);
      }

      else if (number >= 1000 && number <= 999999)
      {
          return  numt_to_text(number / 1000) + "Thousand " + numt_to_text(number % 1000);
      }

      else if (number >= 1000000 && number <= 999999999)
      {
          return  numt_to_text(number / 1000000) + "Million " + numt_to_text(number % 1000000);
      }
      else if (number >= 1000000000 && number <= 999999999999)
      {
          return  numt_to_text(number / 1000000000) + "Billion " + numt_to_text(number % 1000000000);
      }


  }


};

