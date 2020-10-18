#ifndef PIZZA_H__
#define PIZZA_H__
#include<String>
#include<iostream>
using namespace std;

class pizza
{
public:
	string name = "";
	string dough = "";
	string sauce = "";
	virtual void prepare();
	virtual void bake();
	virtual void cut();
	virtual void box();
	string& getName();
};

class NYStyleCheesePizza :public pizza
{
public:
	NYStyleCheesePizza();
};

class ChicagoStyleCheesePizza :public pizza
{
public:
	ChicagoStyleCheesePizza();
	void cut();
};
#endif // !PIZZA_H__



