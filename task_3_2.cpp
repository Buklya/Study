//Напишите программу, которая должна вычислить, сколько раз каждое отдельное слово содержится во введенных данных

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void withVector(vector<string> words);
void withMap(vector<string> words);

int main()
{
   cout << "Enter some words: ";
   vector<string> words;
   string s;
   while(cin >> s)
      words.push_back(s);
   withVector(words);    
   return 0;
}

void withVector(vector<string> words)
{
   vector<string> uniqWords;
   vector<int> count;
   vector<string>::const_iterator it;   
   for (int i = 0; i < words.size(); i++)
   {      
      it = find(uniqWords.begin(), uniqWords.end(), words[i]);
      if(it != uniqWords.end())
      {
         int pos = it - uniqWords.begin();
         count[pos] += 1;
      }
      else
      {
        uniqWords.push_back(words[i]);
        count.push_back(1);
      }
   }   

   for (int i = 0; i < uniqWords.size(); i++)
   {
      cout << uniqWords[i] << " " << count[i] << endl;      
   }   
}

void withMap(vector<string> words)
{
   
}