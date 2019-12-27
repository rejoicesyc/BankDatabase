#ifndef _command_h_
#define _command_h_

#include<iostream>
#include<string>

using namespace::std;

class command{
	//输入命令
	friend istream& operator>>(istream&, command&);
public:
	//欢迎语句
	void welcome();

	//命令判断语句
	bool begin();
	bool waiteTimeOrder();
	bool serveTimeOrder();
	bool stayTime();
	bool help();
	bool quit();

	//bank对象未初始化提示
	void uninitInstruction();

	//help命令提示
	void helpInstruction();

	//异常命令提示
	void exception();
private:
	string cmd;
};

#endif