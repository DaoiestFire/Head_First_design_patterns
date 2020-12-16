#ifndef DECORATOR_H
#define DECORATOR_H
#include"Quackable.h"

class QuackCounter:public Quackable
{
private:
    Quackable* duck;
    static int quack_count;
public:
    QuackCounter(Quackable* d):duck(d) {}
    void quack()
    {
        duck->quack();
        quack_count++;
    }
    static int getQuacks()
    {
        return quack_count;
    }
    void registerObserver(Observer* observer)
    {
        duck->registerObserver(observer);
    }
    void notifyObservers()
    {
        duck->notifyObservers();
    }
    int getNumberOfObservers()
    {
        return duck->getNumberOfObservers();
    }
    ~QuackCounter() {}
};

#endif // DECORATOR_H
