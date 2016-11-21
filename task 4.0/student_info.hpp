#ifndef GUARDO_Student_info_hpp
#define GUARDO_Student_info_hpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student_info
{
   string name;
   double middleterm, finalterm;
   vector<double> homeworkMarks;
};

bool compare(const Student_info & x, const Student_info & y);

istream& read_hw(istream& is, vector<double>& hw);

istream& read (istream & is, Student_info & s);

#endif