#include"GumballMachine.h"

int main()
{
	GumballMachine* gumballMachine = new GumballMachine(5);
	gumballMachine->insertQuarter();
	gumballMachine->turnCrank();

	gumballMachine->insertQuarter();
	gumballMachine->turnCrank();

	gumballMachine->insertQuarter();
	gumballMachine->turnCrank();

	gumballMachine->insertQuarter();
	gumballMachine->turnCrank();

	gumballMachine->insertQuarter();
	gumballMachine->turnCrank();

	gumballMachine->insertQuarter();
	gumballMachine->turnCrank();
}