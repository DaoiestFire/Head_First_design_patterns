#ifndef OBSERVER_H
#define OBSERVER_H
#include<vector>
#include<iostream>
using namespace std;

class Observer;

class QuackObservable
{
public:
    virtual void registerObserver(Observer* observer) {}
    virtual void notifyObservers() {}
    virtual int getNumberOfObservers(){ return 0;}
    virtual string getName()
    {
        return "";
    }
};


class Observer
{
public:
    virtual void update(QuackObservable* duck) {}
};


class Quackologist:public Observer
{
public:
    void update(QuackObservable* duck)
    {
        cout<<"Quackologist: "<<duck->getName()<<" just quacked"<<endl;
    }
};


class Observable:public QuackObservable
{
private:
    vector<Observer*> observers= {};
    QuackObservable* duck;
public:
    Observable(QuackObservable* q):duck(q) {}

    void registerObserver(Observer* o)
    {
        observers.push_back(o);
    }

    void notifyObservers()
    {
        vector<Observer*>::iterator it;
        for(it=observers.begin(); it!=observers.end(); it++)
        {
            Observer* o=*it;
            o->update(duck);
        }
    }
    int getNumberOfObservers()
    {
        return observers.size();
    }
};

#endif // OBSERVER_H
