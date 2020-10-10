#include "duck.h"

int main()
{
	Duck mallard_duck = MallardDuck();
	mallard_duck.performQuack();
	mallard_duck.performFly();

	mallard_duck.setFlyBehavior(new FlyNoWay());
	mallard_duck.setQuackBehavior(new MuteQuack());
	mallard_duck.performQuack();
	mallard_duck.performFly();
	system("pause");
}