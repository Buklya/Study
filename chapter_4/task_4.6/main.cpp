//Напишите программу, которая должна отслеживать оценки нескольких студентов сразу.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <stdexcept>
#include "median.hpp"
#include "student_info.hpp"
#include "grade.hpp"

using std::vector;
using std::string;
using std::cout;
using std::setprecision;
using std::sort;
using std::max;
using std::endl;
using std::streamsize;
using std::cin;
using std::domain_error;


void print_info(const vector<Student_info> students, const string::size_type & maxlen)
{
   for(vector<Student_info>::size_type i = 0; i != students.size(); ++i)
   {
      cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ') << students[i].term;      
      cout << endl;
   }
}
int main()
{
   vector<Student_info> students;
   Student_info record;
   int maxlen = 0;
   while(read(cin, record))
   {
      maxlen = max(maxlen, (int)record.name.size());
      students.push_back(record);
   }
   sort(students.begin(), students.end(), compare);
   print_info(students, maxlen);
   return 0;
}