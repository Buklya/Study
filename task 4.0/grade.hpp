#ifndef GUARD_grade_hpp
#define GUARD_grade_hpp

#include <stdexcept>
#include <vector>
#include "student_info.hpp"
#include "median.hpp"

using namespace std;

double grade(double midterm, double finalterm, double homework);
double grade(double midterm, double finalterm, const vector<double>& homework);
double grade(const Student_info & student);

#endif