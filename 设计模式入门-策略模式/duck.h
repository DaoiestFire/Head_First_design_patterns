#pragma once
#include<iostream>
#ifndef DUCK_H__
#define DUCK_H__

class FlyBehavior
{
public:
	virtual void fly() = 0;
};

class QuackBehavior
{
public:
	virtual void quack() = 0;
};

class FLyWithWings :public FlyBehavior
{
public:
	void fly();
};

class FlyNoWay :public FlyBehavior
{
public:
	void fly();
};

class Quack :public QuackBehavior
{
public:
	void quack();
};

class MuteQuack :public QuackBehavior
{
public:
	void quack();
};

class Duck
{
public:
	void performFly()
	{
		flyBehavior->fly();
	}
	void performQuack()
	{
		quackBehavior->quack();
	}

	void setFlyBehavior(FlyBehavior* fb)
	{
		flyBehavior = fb;
	}

	void setQuackBehavior(QuackBehavior* qb)
	{
		quackBehavior = qb;
	}

	FlyBehavior* flyBehavior;
	QuackBehavior* quackBehavior;
};

class MallardDuck :public Duck
{
public:
	MallardDuck();
};
#endif // !DUCK_H__