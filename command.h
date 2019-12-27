#ifndef _command_h_
#define _command_h_

#include<iostream>
#include<string>

using namespace::std;

class command{
	//��������
	friend istream& operator>>(istream&, command&);
public:
	//��ӭ���
	void welcome();

	//�����ж����
	bool begin();
	bool waiteTimeOrder();
	bool serveTimeOrder();
	bool stayTime();
	bool help();
	bool quit();

	//bank����δ��ʼ����ʾ
	void uninitInstruction();

	//help������ʾ
	void helpInstruction();

	//�쳣������ʾ
	void exception();
private:
	string cmd;
};

#endif