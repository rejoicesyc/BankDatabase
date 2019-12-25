#include "windowQueue.h"
#include "client.h"
#include "myTime.h"
#include<queue>

using namespace::std;

void windowQueue::push(client& c, int window){
	c.waiteTime = time;
	c.departureTime = time + c.serveTime + c.arriveTime;
	c.stayTime = time + c.serveTime;
	c.windowNum = window;
	q.push(c);
	time = time + c.serveTime;
}

client windowQueue::front(){
	return q.front();
}

void windowQueue::pop(){
	time = time - q.front().serveTime;
	q.pop();
}

bool windowQueue::empty(){
	return q.empty();
}

int windowQueue::size(){
	return q.size();
}