//Напишите программу для вывода самого длинного и самого короткого string-значений во введенных данных

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void enterWords(string &longWord, string &shortWord);
void printWord(string s, string word);

int main()
{
   string longWord, shortWord;
   enterWords(longWord, shortWord);
   printWord("the longest word: ", longWord);
   printWord("the shortest word: ", shortWord);   
   return 0;
}

void enterWords(string &longWord, string &shortWord)
{
   cout << "Enter some words: ";   
   string newWord;
   while(cin >> newWord)
   {  
      if(longWord.length() == 0)
      {
         longWord = newWord;
      }         
      if(shortWord.length() == 0)   
      {
         shortWord = newWord;
      }
         
      if(longWord.length() < newWord.length())
      {
         longWord = newWord;
      }
      else if(shortWord.length() > newWord.length())
      {
         shortWord = newWord;
      }
   }     
}

void printWord(string s, string word)
{
   cout << s << word << endl;
}