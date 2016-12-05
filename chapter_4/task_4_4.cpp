/*4.4. А теперь измените свою программу вычисления квадратов, используя вместо 
int-значений значения типа double. Используйте манипуляторы для управления 
выводом данных так, чтобы значения были выровнены по столбцам. */

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

void printSquareNumber(double number, int n, int k)
{    
    streamsize prec = cout.precision();
    for(double i = 1.0; i < number; i++)
    {        
        cout << setw(n) << fixed << setprecision(n) <<  i << " " << setw(k+n) << fixed << setprecision(k) << i*i << endl;
    }    
    cout.precision(prec);
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
    cout << "Enter int number :";
    int numberInt; 
    cin >> numberInt;    
    printSquareNumber(numberInt, order(numberInt-1), order((numberInt-1)*(numberInt-1)));
    cout << "Enter double number :";
    double numberDouble;
    cin >> numberDouble;
    printSquareNumber(numberDouble, 6, 10);
    return 0;
}