#ifndef _myTime_h_
#define _myTime_h_

#include<iostream>

using namespace::std;

//24小时制时间系统类定义（最小分度值：分钟）
class myTime{
	//时间类对象比较函数
	friend bool operator<(const myTime, const myTime);
	friend bool operator>(const myTime, const myTime);
	friend bool operator<=(const myTime, const myTime);
	friend bool operator>=(const myTime, const myTime);
	friend bool operator==(const myTime, const myTime);

	//时间类对象运算函数
	friend myTime operator+(const myTime, const myTime);
	friend myTime operator-(const myTime, const myTime);

	//按照小时:分钟的格式输出时间类对象
	friend ostream& operator<<(ostream&, myTime);
public:
	myTime();

	//生成介于宏定义startTime和endTime之间的随机时间myTime类对象
	void myTimeRandom();

	//生成宏定义serveTime分钟以内的随机时间myTime类对象
	void myTimeRandomMinute();
private:
	//小时，分钟
	int hour;
	int minute;
};

#endif