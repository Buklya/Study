/*4.7. Напишите программу вычисления среднего арифметического от чисел, содержа- 
щихся в векторе типа vector<double>. */

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double arithmeticalMeanValue(const vector<double>& numbers)
{
    if(numbers.empty())
    {
        throw domain_error ("vector is empty");
    }
    double sum = 0;    
    for(int i = 0; i < numbers.size(); i++)
    {
        sum += numbers[i];
    }
    return sum/numbers.size();    
}

void fillVector(vector<double>& numbers, int n)
{
    for(int i = 0; i < n; i++)
    {
        double k = 1.25335;
        numbers.push_back(k*i);
    }
}  

int main()
{
    vector<double> numbers;
    fillVector(numbers, 5);    
    double dValue;
    try
    {
        dValue = arithmeticalMeanValue(numbers);
        cout << setprecision(5) << dValue << endl;
    }
    catch(domain_error e)
    {
        cout << e.what();
    }
    return 0;
}
