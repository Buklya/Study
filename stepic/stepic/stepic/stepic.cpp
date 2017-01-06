// stepic.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

void print(const char *to)
{
	while (*to)
	{
		cout << *to;
		to++;
	}
	cout << endl;
}

void mystrcat(char *&to, char *from)
{
	std::string::size_type sizeTo = strlen(to);
	std::string::size_type sizeFrom = strlen(from);	
	char * temp = new char[sizeTo + sizeFrom + 1];
	for (int i = 0; i < sizeTo; i++)
	{
		temp[i] = to[i];
	}		
	for (int i = 0; i <= sizeFrom; i++)
	{
		temp[sizeTo + i] = from[i];			
	}	
	delete []to;	
	to = temp;		
}

int mystrstr(const char *text, const char *pattern)
{	
	int sizeText = strlen(text);
	int sizePattern = strlen(pattern);
	if (sizePattern > sizeText)
	{
		return -1;
	}
	int k = 0;
	if (*pattern == '\0')
	{
		return k;
	}
	for (int i = 0; i < sizeText; i++) {
		int j = 0;
		if (pattern[j] == text[i]) {
			k = i;
			while (j < sizePattern) {				
				if (j == sizePattern - 1) {
					return k;
				}
				j++;
				i++;
				if (pattern[j] != text[i]) {
					i--;
					break;
				}				
			}
		}
	}
	return -1;
}

void test()
{
	(0 == mystrstr("", "")) ? cout << "OK : 1" << " (" << 0 << " : " << (0 == mystrstr("", "")) << " )" << endl : cout << "Failed : 1" << " (" << 0 << " : " << (0 == mystrstr("", "")) << " )" << endl;
	(0 == mystrstr("a", "")) ? cout << "OK : 2" << " (" << 0 << " : " << (0 == mystrstr("a", "")) << " )" << endl : cout << "Failed : 2" << " (" << 0 << " : " << (0 == mystrstr("a", "")) << " )" << endl;
	(0 == mystrstr("a", "a")) ? cout << "OK : 3" << " (" << 0 << " : " << (0 == mystrstr("a", "a")) << " )" << endl : cout << "Failed : 3" << " (" << 0 << " : " << (0 == mystrstr("a", "a")) << " )" << endl;
	(-1 == mystrstr("a", "b")) ? cout << "OK : 4" << " (" << -1 << " : " << (-1 == mystrstr("a", "b")) << " )" << endl : cout << "Failed : 4" << " (" << -1 << " : " << (-1 == mystrstr("a", "b")) << " )" << endl;

	(0 == mystrstr("aa", "")) ? cout << "OK : 5" << " (" << 0 << " : " << (0 == mystrstr("aa", "")) << " )" << endl : cout << "Failed : 5" << " (" << 0 << " : " << (0 == mystrstr("aa", "")) << " )" << endl;
	(0 == mystrstr("aa", "a")) ? cout << "OK : 6" << " (" << 0 << " : " << (0 == mystrstr("aa", "a")) << " )" << endl : cout << "Failed : 6" << " (" << 0 << " : " << (0 == mystrstr("aa", "a")) << " )" << endl;
	(0 == mystrstr("ab", "a")) ? cout << "OK : 7" << " (" << 0 << " : " << (0 == mystrstr("ab", "a")) << " )" << endl : cout << "Failed : 7" << " (" << 0 << " : " << (0 == mystrstr("ab", "a")) << " )" << endl;
	(1 == mystrstr("ba", "a")) ? cout << "OK : 8" << " (" << 1 << " : " << (1 == mystrstr("ba", "a")) << " )" << endl : cout << "Failed : 8" << " (" << 1 << " : " << (1 == mystrstr("ba", "a")) << " )" << endl;
	(-1 == mystrstr("bb", "a")) ? cout << "OK : 9" << " (" << -1 << " : " << (-1 == mystrstr("bb", "a")) << " )" << endl : cout << "Failed : 9" << " (" << -1 << " : " << (-1 == mystrstr("bb", "a")) << " )" << endl;

	(0 == mystrstr("aaa", "")) ? cout << "OK : 10" << " (" << 0 << " : " << (0 == mystrstr("aaa", "")) << " )" << endl : cout << "Failed : 10" << " (" << 0 << " : " << (0 == mystrstr("aaa", "")) << " )" << endl;
	(0 == mystrstr("aaa", "a")) ? cout << "OK : 11" << " (" << 0 << " : " << (0 == mystrstr("aaa", "a")) << " )" << endl : cout << "Failed : 11" << " (" << 0 << " : " << (0 == mystrstr("aaa", "a")) << " )" << endl;
	(1 == mystrstr("abc", "b")) ? cout << "OK : 12" << " (" << 1 << " : " << (1 == mystrstr("abc", "b")) << " )" << endl : cout << "Failed : 12" << " (" << 1 << " : " << (1 == mystrstr("abc", "b")) << " )" << endl;
	(2 == mystrstr("abc", "c")) ? cout << "OK : 13" << " (" << 2 << " : " << (2 == mystrstr("abc", "c")) << " )" << endl : cout << "Failed : 13" << " (" << 2 << " : " << (2 == mystrstr("abc", "c")) << " )" << endl;
	(-1 == mystrstr("abc", "d")) ? cout << "OK : 14" << " (" << -1 << " : " << (-1 == mystrstr("abc", "d")) << " )" << endl : cout << "Failed : 14" << " (" << -1 << " : " << (-1 == mystrstr("abc", "d")) << " )" << endl;

	(-1 == mystrstr("a", "aa")) ? cout << "OK : 15" << " (" << -1 << " : " << (-1 == mystrstr("a", "aa")) << " )" << endl : cout << "Failed : 15" << " (" << -1 << " : " << (-1 == mystrstr("a", "aa")) << " )" << endl;
	(-1 == mystrstr("a", "ba")) ? cout << "OK : 16" << " (" << -1 << " : " << (-1 == mystrstr("a", "ba")) << " )" << endl : cout << "Failed : 16" << " (" << -1 << " : " << (-1 == mystrstr("a", "ba")) << " )" << endl;
	(-1 == mystrstr("a", "ab")) ? cout << "OK : 17" << " (" << -1 << " : " << (-1 == mystrstr("a", "ab")) << " )" << endl : cout << "Failed : 17" << " (" << -1 << " : " << (-1 == mystrstr("a", "ab")) << " )" << endl;
	(-1 == mystrstr("a", "bb")) ? cout << "OK : 18" << " (" << -1 << " : " << (-1 == mystrstr("a", "bb")) << " )" << endl : cout << "Failed : 18" << " (" << -1 << " : " << (-1 == mystrstr("a", "bb")) << " )" << endl;

	(-1 == mystrstr("a", "aaa")) ? cout << "OK : 19" << " (" << -1 << " : " << (-1 == mystrstr("a", "aaa")) << " )" << endl : cout << "Failed : 19" << " (" << -1 << " : " << (-1 == mystrstr("a", "aaa")) << " )" << endl;
	(-1 == mystrstr("aa", "aaa")) ? cout << "OK : 20" << " (" << -1 << " : " << (-1 == mystrstr("aa", "aaa")) << " )" << endl : cout << "Failed : 20" << " (" << -1 << " : " << (-1 == mystrstr("aa", "aaa")) << " )" << endl;
	(0 == mystrstr("aaa", "aaa")) ? cout << "OK : 21" << " (" << 0 << " : " << (0 == mystrstr("aaa", "aaa")) << " )" << endl : cout << "Failed : 21" << " (" << 0 << " : " << (0 == mystrstr("aaa", "aaa")) << " )" << endl;
	(0 == mystrstr("aaab", "aaa")) ? cout << "OK : 22" << " (" << 0 << " : " << (0 == mystrstr("aaab", "aaa")) << " )" << endl : cout << "Failed : 22" << " (" << 0 << " : " << (0 == mystrstr("aaab", "aaa")) << " )" << endl;
	(1 == mystrstr("baaa", "aaa")) ? cout << "OK : 23" << " (" << 1 << " : " << (1 == mystrstr("baaa", "aaa")) << " )" << endl : cout << "Failed : 23" << " (" << 1 << " : " << (1 == mystrstr("baaa", "aaa")) << " )" << endl;
	(1 == mystrstr("baaaa", "aaa")) ? cout << "OK : 24" << " (" << 1 << " : " << (1 == mystrstr("baaaa", "aaa")) << " )" << endl : cout << "Failed : 24" << " (" << 1 << " : " << (1 == mystrstr("baaaa", "aaa")) << " )" << endl;
	(1 == mystrstr("baaab", "aaa")) ? cout << "OK : 25" << " (" << 1 << " : " << (1 == mystrstr("baaab", "aaa")) << " )" << endl : cout << "Failed : 25" << " (" << 1 << " : " << (1 == mystrstr("baaab", "aaa")) << " )" << endl;
	(-1 == mystrstr("abd", "abc")) ? cout << "OK : 26" << " (" << -1 << " : " << (-1 == mystrstr("abd", "abc")) << " )" << endl : cout << "Failed : 26" << " (" << -1 << " : " << (-1 == mystrstr("abd", "abc")) << " )" << endl;

	(2 == mystrstr("ababc", "abc")) ? cout << "OK : 27" << " (" << 2 << " : " << (2 == mystrstr("ababc", "abc")) << " )" << endl : cout << "Failed : 27" << " (" << 2 << " : " << (2 == mystrstr("ababc", "abc")) << " )" << endl;
	(3 == mystrstr("abdabc", "abc")) ? cout << "OK : 28" << " (" << 3 << " : " << (3 == mystrstr("abdabc", "abc")) << " )" << endl : cout << "Failed : 28" << " (" << 3 << " : " << (3 == mystrstr("abdabc", "abc")) << " )" << endl;

}

int main() {
	/*int n = 6;
	char * to = new char[n];	
	char * from = new char[n];
	strncpy_s(to, n, "hello", n);
	strncpy_s(from, n, "world", n);
	mystrcat(to, from);	
	print(to);
	*/
	test();	
	return 0;
}