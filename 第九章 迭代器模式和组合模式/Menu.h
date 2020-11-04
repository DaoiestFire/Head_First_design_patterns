#pragma once
#include"MenuComponent.h"
#include<vector>
#include<iostream>
#include"Iterator_all.h"


class Menu :public MenuComponent
{
private:
	std::vector<MenuComponent*> menu_item_vector;
	std::string name;
	std::string description;
	bool leaf;
public:
	Menu(std::string n, std::string d, bool l)
	{
		name = n;
		description = d;
		leaf = l;
	}

	void add(MenuComponent* menu_c)
	{
		menu_item_vector.push_back(menu_c);
	}

	void remove(MenuComponent* menu_c)
	{
		for (std::vector<MenuComponent*>::iterator it = menu_item_vector.begin(); it != menu_item_vector.end();)
		{
			if (*it == menu_c)
			{
				menu_item_vector.erase(it);
				break;
			}
		}
	}

	MenuComponent* getChild(int i)
	{
		return menu_item_vector[i];
	}

	std::string getName()
	{
		return name;
	}

	std::string getDesciption()
	{
		return description;
	}

	bool isLeaf()
	{
		return leaf;
	}

	void print()
	{
		std::cout << std::endl << getName();
		std::cout << ",    " << getDesciption() << std::endl;
		std::cout << "--------------------" << std::endl;

		std::vector<MenuComponent*>::iterator it = menu_item_vector.begin();
		while (it != menu_item_vector.end())
		{
			(*it)->print();
			++it;
		}
	}

	Iterator<MenuComponent>* _createIterator()
	{
		return new MenuIterator(menu_item_vector);
	}

	Iterator<MenuComponent>* createIterator()
	{
		return new CompositeIterator(_createIterator());
	}
};

