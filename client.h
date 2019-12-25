#ifndef _client_h_
#define _client_h_

#include "myTime.h"
#include<iostream>

using namespace::std;

class client{
	friend class windowQueue;

	//����ʱ��ȽϺ���
	friend bool arriveTimePrior(client, client);
	friend bool arriveTimePriorEqual(client, client);

	//�ȴ�ʱ�䣨��ͬʱ������ʱ�����򣩱ȽϺ���
	friend bool waiteTimePrior(client, client);

	//ҵ�����ʱ�䣨��ͬʱ������ʱ�����򣩱ȽϺ���
	friend bool serveTimePrior(client, client);

	//�ɿͻ��뿪ʱ�����¿ͻ�����ʱ��ıȽϺ���
	friend bool leaveBeforeArrive(client, client);

	//���һ���û���¼
	friend ostream& operator<<(ostream&, client);
public:
	//������startTime��endTime֮�䵽�����еĿͻ�����ͬʱ����maxServeTime֮�ڵķ���ʱ��
	client();
private:
	//�ͻ��ĵ���ʱ�䣬�뿪ʱ�䣬ҵ�����ʱ�䣬�ȴ�ʱ�䣬����ҵ��Ĵ��ں�
	myTime arriveTime;
	myTime departureTime;
	myTime serveTime;
	myTime waiteTime;
	myTime stayTime;
	int windowNum;
};

#endif