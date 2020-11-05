#pragma once
#include"State.h"
#include<iostream>

class GumballMachine
{
private:
	class NoQuarterState :public State
	{
	public:
		NoQuarterState(GumballMachine* g) :State(g) {}
		void insertQuarter()
		{
			std::cout << "you insert a quarter" << std::endl;
			gumballMachine->setState(gumballMachine->getHasQuarterState());
		}
		void ejectQuarter()
		{
			std::cout << "you havn't inserted a quarter" << std::endl;
		}
		void turnCrank()
		{
			std::cout << "turned,but you havn't inserted a quarter" << std::endl;
		}
		void dispense()
		{
			std::cout << "you need to pay first" << std::endl;
		}
	};
	class SoldOutState :public State
	{
	public:
		SoldOutState(GumballMachine* g) :State(g) {}
		void insertQuarter()
		{
			std::cout << "no more gumballs" << std::endl;
		}
		void ejectQuarter()
		{
			std::cout << "no quarters" << std::endl;
		}
		void turnCrank()
		{
			std::cout << "no more gumballs ,you can't turn crank" << std::endl;
		}
		void dispense()
		{
			std::cout << "mo more gumballs,can not dispense" << std::endl;
		}
	};
	class HasQuarterState :public State
	{
	public:
		HasQuarterState(GumballMachine* g) :State(g) {}
		void insertQuarter()
		{
			std::cout << "you can't insert another quater" << std::endl;
		}
		void ejectQuarter()
		{
			std::cout << "Quarter returned" << std::endl;
			gumballMachine->setState(gumballMachine->getNoQuarterSatete());
		}
		void turnCrank()
		{
			std::cout << "you turned..." << std::endl;
			srand((int)time(0));
			int random_number = random(100);
			if (random_number >= 0 && random_number <= 9)
			{
				gumballMachine->setState(gumballMachine->getWinnerState());
			}
			else
				gumballMachine->setState(gumballMachine->getSoldState());
		}
		void dispense()
		{
			std::cout << "No gumBall dispensed" << std::endl;
		}
	};
	class SoldState :public State
	{
	public:
		SoldState(GumballMachine* g):State(g){}
		void insertQuarter()
		{
			std::cout << "Please wait,we're already giving you a gumball" << std::endl;
		}
		void ejectQuarter()
		{
			std::cout << "sorry,you have truned the crank" << std::endl;
		}
		void turnCrank()
		{
			std::cout << "truning twice doesn't get you another gumball" << std::endl;
		}
		void dispense()
		{
			gumballMachine->releaseBall();
			if (gumballMachine->getCount() > 0)
				gumballMachine->setState(gumballMachine->getNoQuarterSatete());
			else {
				std::cout << "Oops,out of gumballs" << std::endl;
				gumballMachine->setState(gumballMachine->getSoldOutState());
			}
		}
	};
	class WinnerState :public State
	{
	public:
		WinnerState(GumballMachine* g):State(g){}
		void insertQuarter()
		{
			std::cout << "don't insert more qiarters" << std::endl;
		}
		void ejectQuarter()
		{
			std::cout << "can not eject quarters" << std::endl;
		}
		void turnCrank()
		{
			std::cout << "con not turn crank" << std::endl;
		}
		void dispense()
		{
			std::cout << "you are a winner, you can get two gumballs for your quarter" << std::endl;
			gumballMachine->releaseBall();
			if (gumballMachine->getCount() == 0)
				gumballMachine->setState(gumballMachine->getSoldOutState());
			else
			{
				gumballMachine->releaseBall();
				if (gumballMachine->getCount() > 0)
					gumballMachine->setState(gumballMachine->getNoQuarterSatete());
				else
				{
					std::cout << "Oops,out of gumballs" << std::endl;
					gumballMachine->setState(gumballMachine->getSoldOutState());
				}
			}
		}
	};

	State* sold_out_state;
	State* no_quarter_state;
	State* has_quarter_state;
	State* sold_state;
	State* winner_state;

	State* current_state;
	unsigned count = 0;
public:
	GumballMachine(unsigned number_Gumballs)
	{
		sold_out_state = new SoldOutState(this);
		no_quarter_state = new NoQuarterState(this);
		has_quarter_state = new HasQuarterState(this);
		sold_state = new SoldState(this);
		winner_state = new WinnerState(this);
		count = number_Gumballs;
		if (number_Gumballs > 0)
			current_state = no_quarter_state;
	}
	void insertQuarter()
	{
		current_state->insertQuarter();
	}
	void ejectQuarter()
	{
		current_state->ejectQuarter();
	}
	void turnCrank()
	{
		current_state->turnCrank();
		current_state->dispense();
	}
	void setState(State* s)
	{
		current_state = s;
	}
	void releaseBall()
	{
		std::cout << "A gumball comes rolling out the slot" << std::endl;
		if (count != 0)
		{
			--count;
		}
	}

	//getter for each state
	State* getSoldState()
	{
		return sold_state;
	}
	State* getSoldOutState()
	{
		return sold_out_state;
	}
	State* getHasQuarterState()
	{
		return has_quarter_state;
	}
	State* getNoQuarterSatete()
	{
		return no_quarter_state;
	}
	State* getWinnerState()
	{
		return winner_state;
	}

	unsigned getCount()
	{
		return count;
	}
};



