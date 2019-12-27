#include<iostream>
#include<cstdlib>

#include "myTime.h"
#include "defineValues.h"

using namespace::std;

bool operator<(myTime time1, myTime time2){
	if (time1.hour < time2.hour){
		return true;
	}
	else if (time1.hour == time2.hour&&time1.minute < time2.minute){
		return true;
	}
	else{
		return false;
	}
}

bool operator>(myTime time1, myTime time2){
	if (time1.hour > time2.hour){
		return true;
	}
	else if (time1.hour == time2.hour&&time1.minute > time2.minute){
		return true;
	}
	else{
		return false;
	}
}

bool operator<=(myTime time1, myTime time2){
	if (!(time1 > time2)){
		return true;
	}
	else {
		return false;
	}
}

bool operator>=(myTime time1, myTime time2){
	if (!(time1 < time2)){
		return true;
	}
	else{
		return false;
	}
}

bool operator==(myTime time1, myTime time2){
	return time1.hour == time2.hour&&time1.minute == time2.minute;
}

myTime operator+(myTime time1, myTime time2){
	myTime time;
	time.hour = time1.hour + time2.hour;
	time.minute = time1.minute + time2.minute;
	if (time.minute >= 60){
		time.hour += 1;
		time.minute -= 60;
	}
	return time;
}

myTime operator-(myTime time1, myTime time2){
	myTime time;
	time.hour = time1.hour - time2.hour;
	time.minute = time1.minute - time2.minute;
	if (time.minute < 0){
		time.hour -= 1;
		time.minute += 60;
	}
	return time;
}

ostream& operator<<(ostream& os, myTime time){
	if (time.hour < 10){
		cout << 0;
	}
	os << time.hour;
	os << " : ";
	if (time.minute < 10){
		cout << 0;
	}
	os << time.minute;
	return os;
}

myTime::myTime() :hour(0), minute(0){}

void myTime::myTimeRandom(){
	hour = rand() % (endTime - startTime) + startTime;
	minute = rand() % 60;
}

void myTime::myTimeRandomMinute(){
	hour = 0;
	minute = rand() % maxServeTime + 1;
}

int myTime::myTimetoMinute(){
	return hour * 60 + minute;
}