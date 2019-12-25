#ifndef _windowQueue_h_
#define _windowQueue_h_

#include "client.h"
#include "myTime.h"
#include<queue>

using namespace::std;

class windowQueue{
public:
	//空函数初始化窗口
	windowQueue(){}

	//队列操作函数
	//push(client,int)完成对client对象的departureTime,waiteTime,stayTime,windowNum成员的初始化
	void push(client&,int);
	client front();
	void pop();
	bool empty();
	int size();
private:
	//窗口队列，和当期窗口客户服务时间和
	queue<client> q;
	myTime time;
};

#endif