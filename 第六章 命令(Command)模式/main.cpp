#include"Command.h"

int main()
{
	SimpleRemoteControl* remote = new SimpleRemoteControl();
	Light* light = new Light();
	LightOnCommand* lighton = new LightOnCommand(light);

	remote->setCommand(lighton);
	remote->buttonWasPressed();
}