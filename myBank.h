#ifndef _myBank_h_
#define _myBank_h_

#include<iostream>
#include<vector>
#include<queue>
#include "myTime.h"
#include "client.h"
#include "windowQueue.h"
#include "defineValues.h"

using namespace::std;

class myBank{
public:
	myBank();

	//���ݺ궨�������clientNums��������ͻ����ݣ���ʼ������ʱ��ͷ���ʱ�䣩
	//���ݿͻ����ݰ�����ʱ������ģ��������е�ҵ����ˮ������ÿ���ͻ��ĵȴ�ʱ�䣬�뿪ʱ�䣬������
	void myBankSimulation();

	//����ͻ������ж�����ƽ��ʱ�䣨��λ�����ӣ�
	void averageStayTime();

	//���ȴ�ʱ��������ͬʱ������ʱ�����򣩵Ŀͻ��������
	void waiteTimeRank();

	//��ҵ�����ʱ��������ͬʱ������ʱ�����򣩵Ŀͻ��������
	void serveTimeRank();

	//��ʾ�����Ƿ��ѳ�ʼ��
	bool initFinished() const;
private:
	//�ͻ����ݼ������ڶ��м�
	vector<client> datas;
	vector<windowQueue> windows;

	//�����Ƿ���ȫ��ʼ����־
	bool flag;

	//Ϊ�ͻ�ѡ���������ٵĴ��ڣ���������������һ��ʱѡ�񴰿ڱ��С�Ĵ���
	int BestWindow();

	//��һ���µĿͻ���������֮ǰ���뿪ʱ��С�ڲ���client����ʱ��Ŀͻ�����
	void clientIn(client&);

	//�Կͻ����ݸ��ݵ���ȴ�������ʱ����п���
	void arriveTimeSort(int, int);
	void waiteTimeSort(int, int);
	void serveTimeSort(int, int);
};

#endif