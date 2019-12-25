#ifndef _client_h_
#define _client_h_

#include "myTime.h"
#include<iostream>

using namespace::std;

class client{
	friend class windowQueue;

	//到达时间比较函数
	friend bool arriveTimePrior(client, client);
	friend bool arriveTimePriorEqual(client, client);

	//等待时间（相同时按到达时间排序）比较函数
	friend bool waiteTimePrior(client, client);

	//业务办理时间（相同时按到达时间排序）比较函数
	friend bool serveTimePrior(client, client);

	//旧客户离开时间与新客户到达时间的比较函数
	friend bool leaveBeforeArrive(client, client);

	//输出一条用户记录
	friend ostream& operator<<(ostream&, client);
public:
	//产生在startTime到endTime之间到达银行的客户对象，同时生成maxServeTime之内的服务时间
	client();
private:
	//客户的到达时间，离开时间，业务办理时间，等待时间，办理业务的窗口号
	myTime arriveTime;
	myTime departureTime;
	myTime serveTime;
	myTime waiteTime;
	myTime stayTime;
	int windowNum;
};

#endif