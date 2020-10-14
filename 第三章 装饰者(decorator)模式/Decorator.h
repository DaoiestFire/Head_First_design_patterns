#ifndef DECORATOR__H_
#define DECORATOR__H_
#include<String>
using namespace std;


class Beverage {
public:
	string description = "Unkown Beverage";
	virtual string getDescription();
	virtual double cost() = 0;
};

class CondimentDecorator :public Beverage
{
};

//beverage: espresso
class Espresso :public Beverage
{
public:
	Espresso();
	double cost();
};

//beverage: houseblend
class HouseBlend :public Beverage
{
public:
	HouseBlend();
	double cost();
};

//condiment:mocha
class Mocha :public CondimentDecorator
{
private:
	Beverage* beverage;
public:
	Mocha(Beverage*);
	string getDescription();
	double cost();
};

//condiment:soy
class Soy :public CondimentDecorator
{
private:
	Beverage* beverage;
public:
	Soy(Beverage*);
	string getDescription();
	double cost();
};

//condiment:whip
class Whip :public CondimentDecorator
{
private:
	Beverage* beverage;
public:
	Whip(Beverage*);
	string getDescription();
	double cost();
};
#endif