#include"Factory.h"

int main()
{
	PizzaStore* nyStore = new NYPizzaStore();
	PizzaStore* chicagoStore = new ChicagoPizzaStore();

	pizza* p1 = nyStore->orderPizza("cheese");
	pizza* p2 = chicagoStore->orderPizza("cheese");
}