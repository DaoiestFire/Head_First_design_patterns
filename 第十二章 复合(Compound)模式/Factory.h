#ifndef FACTORY_H
#define FACTORY_H
#include"Quackable.h"
#include"Decorator.h"

class AbstractDuckFactory
{
public:
    virtual Quackable* createMallardDuck()=0;
    virtual Quackable* createRedHeadDuck()=0;
    virtual Quackable* createDuckCall()=0;
    virtual Quackable* createRubberDuck()=0;
};

class CountingDuckFactory:public AbstractDuckFactory
{
public:
    Quackable* createMallardDuck()
    {
        return new QuackCounter(new MallardDuck());
    }
    Quackable* createRedHeadDuck()
    {
        return new QuackCounter(new RedheadDuck());
    }
    Quackable* createDuckCall()
    {
        return new QuackCounter(new DuckCall());
    }
    Quackable* createRubberDuck()
    {
        return new QuackCounter(new RubberDuck());
    }
};

#endif // FACTORY_H
