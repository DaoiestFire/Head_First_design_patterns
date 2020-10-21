#include "Singleton.h"
//C++11中可以保证static变量时多线程安全的，在底层实现了加锁操作，所以不需要像以前那样自己写加锁操作
Singleton& Singleton::getInstance()
{
	static Singleton s;
	return s;
}

void Singleton::fun()
{
	cout << "member function" << endl;
}