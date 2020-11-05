#pragma once
#include<ctime>
#include<iostream>
#include<cstdlib>
#define random(x) (rand()%x)

class GumballMachine;

class State
{
protected:
	GumballMachine* gumballMachine;
public:
	State(GumballMachine* g) :gumballMachine(g) {};
	virtual void insertQuarter() = 0;
	virtual void ejectQuarter() = 0;
	virtual void turnCrank() = 0;
	virtual void dispense() = 0;
};
