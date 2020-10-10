#include "duck.h"
void FLyWithWings::fly()
{
	std::cout << "I'm flying!!" << std::endl;
}

void FlyNoWay::fly()
{
	std::cout << "I can't fly" << std::endl;
}

void  Quack::quack()
{
	std::cout << "quack!!" << std::endl;
}

void MuteQuack::quack()
{
	std::cout << "<< Slience>>" << std::endl;
}

MallardDuck::MallardDuck()
{
	quackBehavior = new Quack();
	flyBehavior = new FLyWithWings();
}