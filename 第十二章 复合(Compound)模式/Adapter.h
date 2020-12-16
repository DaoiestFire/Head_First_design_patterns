#ifndef ADAPTER_H
#define ADAPTER_H
#include"Quackable.h"
#include"Observer.h"

class GooseAdapter:public Quackable
{
private:
    Observable* observable;
    Goose* goose;
public:
    GooseAdapter(Goose* g)
    {
        goose=g;
        observable=new Observable(this);
    }
    void quack()
    {
        goose->honk();
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
        return "Goose";
    }
};

#endif // ADAPTER_H
