#include <iostream>
using namespace std;
 
void strcat(char *to, const char *from)
{
    while(*to != 0)
    {
        to++;
    }
    while(*from != 0)
    {
        *to = *from;
        to++;
        from++;
    }    
    *to = '0';
}
 
void print(const char *to)
{
    while(*to != 0)
    {
        cout << *(to++);
    }
}
 
int main() {
	const char * to = "hello";
	const char * from = "world";
	strcat(to, from);
	print(to);
	return 0;
}
 
 