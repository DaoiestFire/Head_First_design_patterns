#ifndef FACTORY_H__
#define FACTORY_H__
#include"pizza.h"


class PizzaStore
{
public:
	pizza* orderPizza(string type);
protected:
	virtual pizza* createPizza(string) = 0;
};

class NYPizzaStore :public PizzaStore
{
	pizza* createPizza(string);
};

class ChicagoPizzaStore :public PizzaStore
{
	pizza* createPizza(string);
};
#endif // !FACTORY_H__
