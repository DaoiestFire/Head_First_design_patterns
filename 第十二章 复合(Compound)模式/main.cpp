#include"Quackable.h"
#include"Adapter.h"
#include"Decorator.h"
#include"Factory.h"
#include"Composite.h"
#include"Observer.h"
class DuckSimulator
{
private:
    void simulate(Quackable* q)
    {
        q->quack();
    }
public:
    void startSimulator(AbstractDuckFactory* factory)
    {
        Quackable* readheadDuck = factory->createRedHeadDuck();
        Quackable* duckCall = factory->createDuckCall();
        Quackable* rubberDuck = factory->createRubberDuck();
        Quackable* gooseDuck = new GooseAdapter(new Goose());//adapter

        cout << "Duck Simulator" <<" with composite-flocks"<< endl;

        Flock* flockOfDucks=new Flock();
        flockOfDucks->add(readheadDuck);
        flockOfDucks->add(duckCall);
        flockOfDucks->add(rubberDuck);
        flockOfDucks->add(gooseDuck);

        Flock* flockOfMallards=new Flock();

        Quackable* mallardDuckOne = factory->createMallardDuck();
        Quackable* mallardDuckTwo = factory->createMallardDuck();
        Quackable* mallardDuckThree = factory->createMallardDuck();
        Quackable* mallardDuckFour = factory->createMallardDuck();

        flockOfMallards->add(mallardDuckOne);
        flockOfMallards->add(mallardDuckTwo);
        flockOfMallards->add(mallardDuckThree);
        flockOfMallards->add(mallardDuckFour);

        Quackologist* quackologist=new Quackologist();
        flockOfDucks->registerObserver(quackologist);

        cout<<"Whole Flock Simulation:"<<endl;
        simulate(flockOfDucks);

        cout<<"Mallard Flock Simulation"<<endl;
        simulate(flockOfMallards);

        cout<<"the duck quacked "<<QuackCounter::getQuacks()<<" times"<<endl;

        cout<<readheadDuck->getNumberOfObservers()<<endl;
    }
};

int main()
{
    DuckSimulator* duck_simulator=new DuckSimulator();
    AbstractDuckFactory* duck_factory=new CountingDuckFactory();

    duck_simulator->startSimulator(duck_factory);
}
