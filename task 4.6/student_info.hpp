#ifndef GUARDO_Student_info_hpp
#define GUARDO_Student_info_hpp

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "grade.hpp"

struct Student_info
{
   std::string name;
   double term;
};

bool compare(const Student_info & x, const Student_info & y);

std::istream& read_hw(std::istream& is, std::vector<double>& hw);

std::istream& read (std::istream & is, Student_info & s);

#endif