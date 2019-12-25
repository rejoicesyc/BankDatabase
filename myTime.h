#ifndef _myTime_h_
#define _myTime_h_

#include<iostream>

using namespace::std;

//24Сʱ��ʱ��ϵͳ�ඨ�壨��С�ֶ�ֵ�����ӣ�
class myTime{
	//ʱ�������ȽϺ���
	friend bool operator<(const myTime, const myTime);
	friend bool operator>(const myTime, const myTime);
	friend bool operator<=(const myTime, const myTime);
	friend bool operator>=(const myTime, const myTime);
	friend bool operator==(const myTime, const myTime);

	//ʱ����������㺯��
	friend myTime operator+(const myTime, const myTime);
	friend myTime operator-(const myTime, const myTime);

	//����Сʱ:���ӵĸ�ʽ���ʱ�������
	friend ostream& operator<<(ostream&, myTime);
public:
	myTime();

	//���ɽ��ں궨��startTime��endTime֮������ʱ��myTime�����
	void myTimeRandom();

	//���ɺ궨��serveTime�������ڵ����ʱ��myTime�����
	void myTimeRandomMinute();
private:
	//Сʱ������
	int hour;
	int minute;
};

#endif