#ifndef QUACKABLE_H
#define QUACKABLE_H
#include<iostream>
#include<string>
#include"Observer.h"
using namespace std;


class Quackable:public QuackObservable
{
public:
    virtual void quack() = 0;
};


class MallardDuck :public Quackable
{
private:
    Observable* observable;
public:
    MallardDuck()
    {
        observable=new Observable(this);
    }
    void quack()
    {
        cout << "Quack" << endl;
        notifyObservers();
    }
    void registerObserver(Observer* observer)
    {
        observable->registerObserver(observer);
    }
    void notifyObservers()
    {
        observable->notifyObservers();
    }

    string getName()
    {
        return "MallardDuck";
    }
};

class RedheadDuck :public Quackable
{
private:
    Observable* observable;
public:
    RedheadDuck()
    {
        observable=new Observable(this);
    }
    void quack()
    {
        cout << "Quack" << endl;
        notifyObservers();
    }
    void registerObserver(Observer* observer)
    {
        observable->registerObserver(observer);
    }
    void notifyObservers()
    {
        observable->notifyObservers();
    }
    string getName()
    {
        return "RedHeadDuck";
    }
    int getNumberOfObservers()
    {
        return observable->getNumberOfObservers();
    }
};

class DuckCall :public Quackable
{
private:
    Observable* observable;
public:
    DuckCall()
    {
        observable=new Observable(this);
    }
    void quack()
    {
        cout << "Kwak" << endl;
        notifyObservers();
    }
    void registerObserver(Observer* observer)
    {
        observable->registerObserver(observer);
    }
    void notifyObservers()
    {
        observable->notifyObservers();
    }
    string getName()
    {
        return "DuckCall";
    }
};

class RubberDuck :public Quackable
{
private:
    Observable* observable;
public:
    RubberDuck()
    {
        observable=new Observable(this);
    }
    void quack()
    {
        cout << "Squeak" << endl;
        notifyObservers();
    }
    void registerObserver(Observer* observer)
    {
        observable->registerObserver(observer);
    }
    void notifyObservers()
    {
        observable->notifyObservers();
    }
    string getName()
    {
        return "RubberDuck";
    }
};

//goose
class Goose
{
public:
    void honk()
    {
        cout << "Honk" << endl;
    }
};

#endif // QUACKABLE_H
