#ifndef COMMAND_H__
#define COMMAND_H__
#include<iostream>
using namespace std;

class Light
{
public:
	void on()
	{
		cout << "light is on" << endl;
	}
	void off()
	{
		cout << "light is off" << endl;
	}
};

class Command
{
public:
	virtual void execute() = 0;
};

class LightOnCommand :public Command
{
private:
	Light* light;
public:
	LightOnCommand(Light* l)
	{
		light = l;
	}

	void execute()
	{
		light->on();
	}
};

class SimpleRemoteControl
{
private:
	Command* slot;
public:
	void setCommand(Command* c)
	{
		slot = c;
	}
	void buttonWasPressed()
	{
		slot->execute();
	}
};
#endif // !COMMAND_H__