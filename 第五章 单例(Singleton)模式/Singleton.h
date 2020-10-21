#ifndef SIGLETON_H__
#define SIGLETON_H__
#include<iostream>
using namespace std;


class Singleton
{
private:
	Singleton() {};
public:
	static Singleton& getInstance();
	void fun();
};
#endif // !SIGLETON_H__