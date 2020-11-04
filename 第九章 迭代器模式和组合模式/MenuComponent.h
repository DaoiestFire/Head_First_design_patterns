#pragma once
#include<String>
#include"Iterator.h"

class MenuComponent
{
public:
	virtual void add(MenuComponent* m)
	{
		throw "Unsupported Operation";
	}
	virtual void remove(MenuComponent* m)
	{
		throw "Unsupported Operation";
	}
	virtual MenuComponent* getChild(int i)
	{
		throw "Unsupported Operation";
	}
	virtual std::string getName()
	{
		throw "Unsupported Operation";
	}
	virtual std::string getDesciption()
	{
		throw "Unsupported Operation";
	}
	virtual double getPrice()
	{
		throw "Unsupported Operation";
	}
	virtual bool isVegetarian()
	{
		throw "Unsupported Operation";
	}
	virtual void print()
	{
		throw "Unsupported Operation";
	}
	virtual bool isLeaf()
	{
		throw "Unsupported Operation";
	}
	virtual Iterator<MenuComponent>* createIterator() = 0;
};
