#include "extract_fails.hpp"
using std::vector;

/*
vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;
    for(vector<Student_info>::size_type i = 0; i != students.size(); i++)
    {
        if(fgrade(students[i]))
        {
            fail.push_back(students[i]);
            students.erase(students.begin() + i);
        }
        else
        {
            ++i;
        }
    }    
    return fail;
}
*/

vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vector<Student_info>::const_iterator iter = students.begin();
    while(iter != students.end())
    {
        if(fgrade(*iter))
        {
            fail.push_back(*iter);
            iter = students.erase(iter);
        }
        else
        {
            ++iter;
        }
    }    
    return fail;
}