#include <iostream>
using namespace std;

int power(int x, unsigned int p) {
    int answer = 1;
    /* считаем answer */
    for(unsigned int i = 0; i < p; i++)
    {
        answer *= x;                
    }
    return answer;
}

int main ()
{
    int i = 2;
    unsigned int p = 0;    
    cout << power(i, p) << endl;
    return 0;
}
