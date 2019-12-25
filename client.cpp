#include "client.h"
#include<iostream>

using namespace::std;

bool arriveTimePrior(client c1, client c2){
	return c1.arriveTime < c2.arriveTime;
}

bool arriveTimePriorEqual(client c1, client c2){
	return c1.arriveTime <= c2.arriveTime;
}

bool waiteTimePrior(client c1, client c2){
	if (c1.waiteTime < c2.waiteTime){
		return true;
	}
	else if (c1.waiteTime == c2.waiteTime){
		return c1.arriveTime < c2.arriveTime;
	}
	else{
		return false;
	}
}

bool serveTimePrior(client c1, client c2){
	if (c1.serveTime < c2.serveTime){
		return true;
	}
	else if (c1.serveTime == c2.serveTime){
		return c1.arriveTime < c2.arriveTime;
	}
	else{
		return false;
	}
}

bool leaveBeforeArrive(client c1, client c2){
	return c1.departureTime <= c2.arriveTime;
}

ostream& operator<<(ostream& os, client c){
	cout << c.arriveTime << '  ' << c.departureTime << '  ' << c.serveTime
		<< '  ' << c.waiteTime << '  ' << c.windowNum + 1 << endl;
	return os;
}

client::client() :arriveTime(), departureTime(), serveTime(), waiteTime(), windowNum(0){
	arriveTime.myTimeRandom();
	serveTime.myTimeRandomMinute();
}