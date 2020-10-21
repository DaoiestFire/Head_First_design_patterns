#include "Singleton.h"

int main()
{
	Singleton& s1 = Singleton::getInstance();
	Singleton& s2 = Singleton::getInstance();
	if (&s1 == &s2)
		cout << "same" << endl;
	else
		cout << "not same" << endl;
	system("pause");
}