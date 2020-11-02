#ifndef ADAPTER_H__
#define ADAPTER_H__
#include <iostream>
using namespace std;

class Target
{
public:
	virtual void request() = 0;
};

class Adaptee
{
public:
	void specificRequest();
};

class Adapter :public Target
{
private:
	Adaptee* adp;
public:
	Adapter(Adaptee* a)
	{
		adp = a;
	}
	void request()
	{
		adp->specificRequest();
	}
};
#endif // !ADAPTER_H__
