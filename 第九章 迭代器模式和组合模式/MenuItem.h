#pragma once
#include"MenuComponent.h"
#include<iostream>
#include"Iterator_all.h"

class MenuItem:public MenuComponent
{
private:
	std::string name;
	std::string description;
	double price;
	bool vegetarian;
	bool leaf;
public:
	MenuItem(std::string n, std::string d, bool v, double p, bool l)
	{
		name = n;
		description = d;
		price = p;
		vegetarian = v;
		leaf = l;
	}

	std::string getName()
	{
		return name;
	}

	std::string getDesciption()
	{
		return description;
	}

	double getPrice()
	{
		return price;
	}

	bool isVegetarian()
	{
		return vegetarian;
	}

	bool isLeaf()
	{
		return leaf;
	}

	void print()
	{
		std::cout << "     " << getName();
		if (isVegetarian())
		{
			std::cout << "(v)";
		}
		std::cout << ",   " << getPrice() << std::endl;
		std::cout << "            ----" << getDesciption() << std::endl;
	}

	Iterator<MenuComponent>* createIterator()
	{
		return new NullIterator();
	}
};

