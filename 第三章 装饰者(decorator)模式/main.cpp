#include"Decorator.h"
#include<iostream>

int main()
{
	Beverage* beverage = new Espresso();
	cout << beverage->getDescription() << " $" << beverage->cost() << endl;

	Beverage* beverage2 = new HouseBlend();
	beverage2 = new Soy(beverage2);
	beverage2 = new Whip(beverage2);
	beverage2 = new Mocha(beverage2);
	cout << beverage2->getDescription() << " $" << beverage2->cost() << endl;
}