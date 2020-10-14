#include "Decorator.h"
string Beverage::getDescription()
{
	return description;
}

//func for espresso
Espresso::Espresso()
{
	description = "Espresso";
}

double Espresso::cost()
{
	return 1.99;
}

HouseBlend::HouseBlend()
{
	description = "House Blend Coffe";
}

double HouseBlend::cost()
{
	return 0.89;
}

//func for mocha
Mocha::Mocha(Beverage* b)
{
	beverage = b;
}

string Mocha::getDescription()
{
	return beverage->getDescription() + ", Mocha";
}

double Mocha::cost()
{
	return 0.2 + beverage->cost();
}

//func for soy
Soy::Soy(Beverage* b)
{
	beverage = b;
}

string Soy::getDescription()
{
	return beverage->getDescription() + ", Soy";
}

double Soy::cost()
{
	return 0.15 + beverage->cost();
}

//func for whip
Whip::Whip(Beverage* b)
{
	beverage = b;
}

string Whip::getDescription()
{
	return beverage->getDescription() + ", Whip";
}

double Whip::cost()
{
	return 0.1 + beverage->cost();
}


