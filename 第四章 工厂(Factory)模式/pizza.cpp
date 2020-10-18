#include "pizza.h"

void pizza::prepare()
{
	cout << "Peparing... " << name << endl;
}

void pizza::bake()
{
	cout << "Baking..." << endl;
}

void pizza::cut()
{
	cout << "Cuting" << endl;
}

void pizza::box()
{
	cout << "Boxing" << endl;
}

string& pizza::getName()
{
	return name;
}

NYStyleCheesePizza::NYStyleCheesePizza()
{
	name = "NY Style Sauce and Cheese Pizza";
}

ChicagoStyleCheesePizza::ChicagoStyleCheesePizza()
{
	name = "Chicago Style Deep Dish Cheese Pizza";
}

void ChicagoStyleCheesePizza::cut()
{
	cout << "Cutting the pizza into square slices" << endl;
}