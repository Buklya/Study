/*4.5. Напишите функцию, которая считывает слова из входного потока и сохраняет их 
в векторе. Используйте эту функцию для написания программ, которые подсчи- 
тывают количество слов во входном потоке, а также фиксируют, сколько раз 
встречается в нем каждое слово. */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

void enterWords(vector<string>& words)
{
    string word;
    while(cin >> word)
    {
        words.push_back(word);
    }
}

void withMap(vector<string> words)
{
    map<string,int> uniqWords;
    map<string, int>::const_iterator it;
    int number = 0;
    for (int i = 0; i < words.size(); i++)
    {
        number++;
        uniqWords[words[i]]++;
    }	
    cout << "count of words is " << number << endl;	
    for (it = uniqWords.begin(); it != uniqWords.end(); it++)
	{
		cout<<(*it).first<< ": " <<(*it).second<<endl;
	}
}

int main()
{
    vector<string> words;
    enterWords(words);
    withMap(words);
    return 0;
}