#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
   cout << "Enter your name: ";
   string name;
   cin >> name;
   cout << "\nHello, " << name << endl;

   cout << "Enter your middle and final marks for exams: ";
   double middterm, finalterm;
   cin >> middterm >> finalterm;

   cout << "Enter your marks for hometasks: ";
   vector<double> homework;
   double x;
   while(cin >> x)
      homework.push_back(x);

   typedef vector<double>::size_type vec_size;
   vec_size size = homework.size();
   if(size == 0)  
   {
      cout << "empty";
      return 1;
   }

   sort(homework.begin(), homework.end());
   vec_size mid = size/2;
   double median;
   median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2
                          : homework[mid];

   streamsize prec = cout.precision();
   cout << "Your total mark is " << setprecision(3)
   << 0.2 * middterm + 0.4 * finalterm + 0.4 * median
   << setprecision(prec) << endl;

   return 0;     
}