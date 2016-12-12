#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdio>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

vector<string> split(const string & s)
{
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    while(i != s.size())
    {
        while(i != s.size() && isspace(s[i]))
        {
            ++i;
        }
        string_size j = i;
        while(j != s.size() && !isspace(s[j]))
        {
            ++j;
        }
        if(i != j)
        {
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}

int main()
{
    string test;
    cout << "Enter string\n";
    getline(cin, test);    
    vector<string> split_test = split(test);
    for(int i = 0; i != split_test.size(); i++)
    {
        cout << split_test[i] << endl;
    }
    string s; 
    while (cin >> s) 
        cout << s << endl; 

    return 0;
}