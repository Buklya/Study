#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ios>

using namespace std;

int main()
{
   cout << "Enter your name: ";
   string name;
   cin >> name;

   cout << "Enter your middle and final marks: ";
   double middleMark, finalMark;
   cin >> middleMark >> finalMark;

   cout << "Enter your homework marks: ";
   vector<double> homeworkMarks;
   double x;
   while(cin >> x)
   {
      homeworkMarks.push_back(x);
   }

   typedef vector<double>::size_type vector_size;
   vector_size size = homeworkMarks.size();   
   if(size == 0)
   {
      cout << "empty";
      return 1;
   } 

   sort(homeworkMarks.begin(), homeworkMarks.end());
   vector_size mid = size/2;
   double median;
   median = size%2 == 0 ? (homeworkMarks[mid] + homeworkMarks[mid - 1]) /2
                        : homeworkMarks[mid];
   streamsize prec = cout.precision();
   cout << "Your mark is " << setprecision(3)
   << 0.2 * middleMark + 0.4 * finalMark + 0.4 * median
   << setprecision(prec) << endl;
   return 0;                      
}