#ifndef COMPOSITE_H
#define COMPOSITE_H
#include"Quackable.h"
#include<vector>


class Flock:public Quackable
{
private:
    vector<Quackable*> quackers= {};
public:
    void add(Quackable* q)
    {
        quackers.push_back(q);
    }

    void quack()
    {
        vector<Quackable*>::iterator iter;
        for(iter=quackers.begin(); iter!=quackers.end(); iter++)
        {
            Quackable* q=*iter;
            q->quack();
        }
    }

    void registerObserver(Observer* observer)
    {
        vector<Quackable*>::iterator iter;
        for(iter=quackers.begin(); iter!=quackers.end(); iter++)
        {
            Quackable* q=*iter;
            q->registerObserver(observer);
        }
    }
};

#endif // COMPOSITE_H
