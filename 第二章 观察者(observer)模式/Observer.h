#ifndef OBSERVER_H__
#define OBSERVER_H__
#include<vector>


class Observer
{
public:
	virtual void update(float temp, float humidity, float pressure) = 0;
};

class Subject
{
public:
	virtual void registerObserver(Observer* o) = 0;
	virtual void removeObserver(Observer* o) = 0;
	virtual void notifyObservers() = 0;
};

class DisplayElement
{
public:
	virtual void display() = 0;
};

class WeatherData :public Subject
{
private:
	std::vector<Observer*> observers;
	float temperature = 0;
	float humidity = 0;
	float pressure = 0;
public:
	WeatherData();
	void registerObserver(Observer*);
	void removeObserver(Observer*);
	void notifyObservers();
	void measurementsChanged();
	void setMeasurements(float, float, float);
};

class CurrentConditionDisplay :public Observer, public DisplayElement
{
private:
	float temperature;
	float humdity;
	Subject* weatherData;
public:
	CurrentConditionDisplay(Subject*);
	void update(float, float, float);
	void display();
};
#endif//!OBSERVER_H__