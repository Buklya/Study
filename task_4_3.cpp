/*4.3. Что произойдет, если переписать предыдущую программу так, чтобы она выводила 
числа (и их квадраты) до 1000 (но не включала значение 1000), и при этом пренеб- 
речь изменением аргументов, передаваемых функции setw? Перепишите программу 
так, чтобы она была более защищенной "перед лицом" изменений, которые позво- 
ляют переменной i расти, не корректируя аргументы функции setw. 
*/

#include <iostream>
#include <iomanip>
using namespace std;

void printSquareNumber(int number, int n, int k)
{
    for(int i = 1; i < number; i++)
    {
        cout << setw(n) << i << " " << setw(k) << i*i << endl;
    }    
}

int order(int number)
{
    int n = 0;    
    while(number > 0.9)
    {
        number = number/10;
        n++;
    }    
    return n;
}

int main()
{
    cout << "Enter number :";
    int number; 
    cin >> number;    
    printSquareNumber(number, order(number-1), order((number-1)*(number-1)));
    return 0;
}