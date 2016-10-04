//Напишите программу для вывода самого длинного и самого короткого string-значений во введенных данных

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
   cout << "Enter some words: ";
   vector<string> words;
   string s;
   while(cin >> s)
      words.push_back(s);
   string longWord = words[0];
   string shortWord = words[0];   
   for (int i = 1; i < words.size(); i++)
   {      
      if(longWord.length() < words[i].length())
      {
         longWord = words[i];
      }
      else if(shortWord.length() > words[i].length())
      {
         shortWord = words[i];
      }
   }   
   cout << "the longest word: " << longWord << endl;
   cout << "the shortest word: " << shortWord << endl;
   return 0;
}