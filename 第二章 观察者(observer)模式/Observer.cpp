#include "Observer.h"
#include<iostream>

WeatherData::WeatherData() {}

void WeatherData::registerObserver(Observer* o)
{
	observers.push_back(o);
}

void WeatherData::removeObserver(Observer* o)
{
	std::vector<Observer*>::iterator iter = std::find(observers.begin(), observers.end(), o);
	if (iter != observers.end()) observers.erase(iter);
}

void WeatherData::notifyObservers()
{
	for (auto observer : observers)
	{
		observer->update(temperature, humidity, pressure);
	}
}

void WeatherData::measurementsChanged()
{
	notifyObservers();
}

void WeatherData::setMeasurements(float t, float h, float p)
{
	temperature = t;
	humidity = h;
	pressure = p;
	measurementsChanged();
}

CurrentConditionDisplay::CurrentConditionDisplay(Subject* s)
{
	this->weatherData = s;
	weatherData->registerObserver(this);
}

void CurrentConditionDisplay::update(float t, float h, float p)
{
	temperature = t;
	humdity = h;
	display();
}

void CurrentConditionDisplay::display()
{
	std::cout << "[temperature]: " << temperature << " [humidity]: " << humdity << std::endl;
}