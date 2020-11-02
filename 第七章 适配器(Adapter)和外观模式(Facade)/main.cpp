#include"Adapter.h"

int main()
{
	Adaptee* ade = new Adaptee();
	Adapter* a = new Adapter(ade);
	a->request();
}