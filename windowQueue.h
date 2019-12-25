#ifndef _windowQueue_h_
#define _windowQueue_h_

#include "client.h"
#include "myTime.h"
#include<queue>

using namespace::std;

class windowQueue{
public:
	//�պ�����ʼ������
	windowQueue(){}

	//���в�������
	//push(client,int)��ɶ�client�����departureTime,waiteTime,stayTime,windowNum��Ա�ĳ�ʼ��
	void push(client&,int);
	client front();
	void pop();
	bool empty();
	int size();
private:
	//���ڶ��У��͵��ڴ��ڿͻ�����ʱ���
	queue<client> q;
	myTime time;
};

#endif