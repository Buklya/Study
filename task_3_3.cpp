//Напишите программу для вывода самого длинного и самого короткого string-значений во введенных данных

#include <iostream>
#include <string>
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
   cin >> newWord;
   longWord = shortWord =newWord;
   while(cin >> newWord)
   {  
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