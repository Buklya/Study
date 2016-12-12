#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>

using std::string;
using std::vector;
using std::domain_error;
using std::cout;
using std::endl;
using std::max;

string::size_type width(const vector<string>& vs)
{
    if(vs.empty())
    {
        throw domain_error("empty");
    }
      
    string::size_type maxlen = vs[0].size();
    for(string::size_type i = 0; i < vs.size(); ++i)
    {
        maxlen = max(maxlen, vs[i].size());            
    }
    return maxlen;
}

vector<string> frame(const vector<string>& vs)
{
    vector<string> ret;
    string::size_type maxlen = width(vs);
    string board(maxlen + 4, '*');
    ret.push_back(board);
    for(string::size_type i = 0; i < vs.size(); ++i)
    {
        ret.push_back("* " + vs[i] + string(maxlen - vs[i].size(), ' ') + " *");       
    }    
    ret.push_back(board);
    return ret;
}

void printFrame(const vector<string>& vs)
{
    for(string::size_type i = 0; i < vs.size(); ++i)
    {
        cout << vs[i] << endl;
    }
}
vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
    vector<string> ret = top;
    ret.insert(ret.end(), bottom.begin(), bottom.end());
    return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;
    string::size_type widthl = width(left);
    vector<string>::const_iterator i = left.begin();
    vector<string>::const_iterator j = right.begin();
    while(i != left.end() || j != right.end())
    {
        string s;
        if(i != left.end())
        {
            s = *i++;
        }
        s += string(widthl - s.size(), ' ');
        if(j != right.end())
        {
            s += *j++;
        }
        ret.push_back(s);
    }
    return ret;
}

int main()
{
    vector<string> s = {"cat", "dog", "lala la"};     
    vector<string> vsFrame;   
    try
    {
        vsFrame = frame(s);        
    }
    catch(domain_error e)
    {
        cout << e.what();
    }
    printFrame(vcat(s, vsFrame));
    printFrame(hcat(s, vsFrame));
}