#ifndef TEMPLATE_H__
#define TEMPLATE_H__
#include<iostream>
using namespace std;

class CaffeineBeverage
{
public:
	void prepareRecipe()
	{
		boilWater();
		brew();
		pourInCup();
		addCondiments();
	}

	virtual void brew() = 0;
	virtual void addCondiments() = 0;
	void boilWater()
	{
		cout << "Boiling water" << endl;
	}

	void pourInCup()
	{
		cout << "Pouring into cup" << endl;
	}
};


class Tea :public CaffeineBeverage
{
public:
	virtual void brew()
	{
		cout << "Steeping the tea" << endl;
	}

	virtual void addCondiments()
	{
		cout << "Adding lemon" << endl;
	}
};

class Coffee :public CaffeineBeverage
{
public:
	virtual void brew()
	{
		cout << "Dripping Coffee through filter" << endl;
	}

	virtual void addCondiments()
	{
		cout << "Adding sugar and Milk" << endl;
	}
};


#endif // !TEMPLATE_H__