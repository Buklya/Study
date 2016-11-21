#include "median.hpp"

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