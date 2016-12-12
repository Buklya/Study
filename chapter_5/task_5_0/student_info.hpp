#ifndef GUARDO_Student_info_hpp
#define GUARDO_Student_info_hpp

#include <iostream>
#include <string>
#include <vector>

struct Student_info
{
   std::string name;
   double middleterm, finalterm;
   std::vector<double> homeworkMarks;
};

bool compare(const Student_info & x, const Student_info & y);

std::istream& read_hw(std::istream& is, std::vector<double>& hw);

std::istream& read (std::istream & is, Student_info & s);

#endif