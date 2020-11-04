#pragma once
#include"MenuComponent.h"
#include <iostream>

class Waitress
{
private:
	MenuComponent* allMenus;
public:
	Waitress(MenuComponent* m)
	{
		allMenus = m;
	}

	void printMenu()
	{
		allMenus->print();
	}

	void printVegetarianMenu()
	{
		Iterator<MenuComponent>* it = allMenus->createIterator();
		std::cout << "\nVEGETARIAN MENU\n---------------------" << std::endl;
		while (it->hasNext())
		{
			MenuComponent* menuComponent = it->next();
			if (menuComponent->isVegetarian())
				menuComponent->print();
		}
	}
};

