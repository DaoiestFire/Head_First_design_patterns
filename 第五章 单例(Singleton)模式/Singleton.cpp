#include "Singleton.h"
//C++11�п��Ա�֤static����ʱ���̰߳�ȫ�ģ��ڵײ�ʵ���˼������������Բ���Ҫ����ǰ�����Լ�д��������
Singleton& Singleton::getInstance()
{
	static Singleton s;
	return s;
}

void Singleton::fun()
{
	cout << "member function" << endl;
}