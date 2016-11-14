//Напишите программу, которая должна отслеживать оценки нескольких студентов сразу.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <stdexcept>

using namespace std;
struct Student_info
{
   string name;
   double middleterm, finalterm;
   vector<double> homeworkMarks;
};

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

double grade(double midterm, double finalterm, double homework)
{
   return 0.2 * midterm + 0.4 * finalterm + 0.4 * homework;
}

double median(vector<double> vec)
{
   typedef vector<double>::size_type vec_size;
   vec_size size = vec.size();
   if(size == 0)  
   {
      throw domain_error("empty");      
   }
   sort(vec.begin(), vec.end());
   vec_size mid = size/2;
   return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

double grade(double midterm, double finalterm, const vector<double>& homework)
{
   if(homework.size() == 0)
      throw domain_error("empty");
   return grade(midterm, finalterm, median(homework));
}

double grade(const Student_info & student)
{   
   return grade(student.middleterm, student.finalterm, student.homeworkMarks);
}

void print_info(const vector<Student_info> students, const string::size_type & maxlen)
{
   for(vector<Student_info>::size_type i = 0; i != students.size(); ++i)
   {
      cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');
      try
      {
         double final_grade = grade(students[i]);
         streamsize prec = cout.precision();
         cout << setprecision(3) << final_grade << setprecision(prec);
      }
      catch (domain_error e) 
      {
         cout << e.what();
      }
      cout << endl;
   }
}
int main()
{
   vector<Student_info> students;
   Student_info record;
   string::size_type maxlen = 0;
   while(read(cin, record))
   {
      maxlen = max(maxlen, record.name.size());
      students.push_back(record);
   }
   sort(students.begin(), students.end(), compare);
   print_info(students, maxlen);
   return 0;
}