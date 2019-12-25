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

//����ϵͳ�ඨ��
class myBank{
public:
	//���ݺ궨�������clientNums��������ͻ����ݣ���������ʱ��ͷ���ʱ�䣩
	myBank();

	//���ݿͻ����ݰ�����ʱ������ģ��������е�ҵ����ˮ������ÿ���ͻ��ĵȴ�ʱ�䣬�뿪ʱ�䣬������
	void myBankSimulation();

	//����ͻ������ж�����ƽ��ʱ�䣨�ȴ�ʱ��+ҵ�����ʱ�䣩
	//float averageStayTime();

	//���ȴ�ʱ��������ͬʱ������ʱ�����򣩵Ŀͻ��������
	//void waiteTimeRnak();

	//��ҵ�����ʱ��������ͬʱ������ʱ�����򣩵Ŀͻ��������
	//void serveTimeRank();
private:
	//�ͻ����ݼ������ڶ��м�
	vector<client> datas;
	vector<windowQueue> windows;

	//Ϊ�ͻ�ѡ���������ٵĴ��ڣ���������������һ��ʱѡ�񴰿ڱ��С�Ĵ���
	int BestWindow();

	//��һ���µĿͻ���������֮ǰ���뿪ʱ��С�ڲ���client����ʱ��Ŀͻ�����
	void clientIn(client&);

	//�Կͻ����ݸ��ݵ���ʱ����п���
	void arriveTimeSort(int, int);
};

#endif