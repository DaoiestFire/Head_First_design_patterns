#include "Factory.h"

pizza* PizzaStore::orderPizza(string type)
{
	pizza* p;
	p = createPizza(type);
	p->prepare();
	p->bake();
	p->cut();
	p->box();

	return p;
}

pizza* NYPizzaStore::createPizza(string s)
{
	if (s == "cheese")
	{
		return new NYStyleCheesePizza();
	}
}

pizza* ChicagoPizzaStore::createPizza(string s)
{
	if (s == "cheese")
	{
		return new ChicagoStyleCheesePizza();
	}
}