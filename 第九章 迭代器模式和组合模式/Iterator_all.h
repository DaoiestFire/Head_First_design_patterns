#pragma once
#include<vector>
#include"Iterator.h"
#include"MenuComponent.h"
#include<stack>


class NullIterator :public Iterator<MenuComponent>
{
public:
	MenuComponent* next()
	{
		return nullptr;
	}
	bool hasNext()
	{
		return false;
	}
};

//iterator for vector£¨Menu£©
class MenuIterator :public Iterator<MenuComponent>
{
private:
	std::vector<MenuComponent*> items;
	int position;
public:
	MenuIterator(std::vector<MenuComponent*> _items) :items(_items), position(0) {}
	MenuComponent* next()
	{
		MenuComponent* component = items[position];
		position++;
		return component;
	}

	bool hasNext()
	{
		if (position >= items.size())
			return false;
		else
			return true;
	}
	~MenuIterator() {};
};

class CompositeIterator :public Iterator<MenuComponent>
{
private:
	std::stack<Iterator<MenuComponent>*> s;
public:
	CompositeIterator(Iterator<MenuComponent>* it)
	{
		s.push(it);
	}
	MenuComponent* next()
	{
		if (hasNext())
		{
			Iterator<MenuComponent>* it = s.top();
			MenuComponent* component = it->next();
			if (!component->isLeaf())
			{
				s.push(component->createIterator());
				return next();
			}
			else
				return component;
		}
		else
			return nullptr;
	}

	bool hasNext()
	{
		if (s.empty())
			return false;
		else
		{
			Iterator<MenuComponent>* it = s.top();
			if (!it->hasNext())
			{
				s.pop();
				return hasNext();
			}
			else
				return true;
		}
	}
};