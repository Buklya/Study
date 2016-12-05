#include "student_info.hpp"

using std::istream;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;

bool compare(const Student_info & x, const Student_info & y)
{
   return x.name < y.name;
}

istream& read_hw(istream& is, vector<double>& hw)
{
   if(is)
   {
      hw.clear();
      double x;
      while(is >> x)
         hw.push_back(x);
      cin.fill();
      fflush(stdin);   
      is.clear();   
   }
   return is;
}

istream& read (istream & is, Student_info & s)
{
    double middleterm, finalterm;
    vector<double> homeworkMarks;
    cout << "Enter your name: ";
    is >> s.name;
    cout << "Enter middterm: ";
    is >> middleterm;
    cout << "Enter finalterm: ";
    is >> finalterm;
    cout << "Enter marks for homework: ";
    read_hw(is, homeworkMarks);
    try
      {
         s.term = grade(middleterm, finalterm, homeworkMarks);
      }
      catch (domain_error e) 
      {
         cout << e.what();
      }    
    cout << endl;
    return is;
}