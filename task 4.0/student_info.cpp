#include "student_info.hpp"

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
   cout << "Enter your name: ";
   is >> s.name;
   cout << "Enter middterm: ";
   is >> s.middleterm;
   cout << "Enter finalterm: ";
   is >> s.finalterm;
   cout << "Enter marks for homework: ";
   read_hw(is, s.homeworkMarks);
   cout << endl;
   return is;
}