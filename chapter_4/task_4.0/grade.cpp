#include "grade.hpp"

using std::domain_error;
using std::vector;

double grade(double midterm, double finalterm, double homework)
{
   return 0.2 * midterm + 0.4 * finalterm + 0.4 * homework;
}

double grade(double midterm, double finalterm, const vector <double> & homework)
{
   if(homework.size() == 0)
      throw domain_error("empty");
   return grade(midterm, finalterm, median(homework));
}

double grade(const Student_info & student)
{   
   return grade(student.middleterm, student.finalterm, student.homeworkMarks);
}