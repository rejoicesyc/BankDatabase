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

//银行系统类定义
class myBank{
public:
	//根据宏定义的人数clientNums随机产生客户数据（包括到达时间和服务时间）
	myBank();

	//根据客户数据按到达时间排序模拟输出银行的业务流水，计算每个客户的等待时间，离开时间，办理窗口
	void myBankSimulation();

	//计算客户在银行逗留的平均时间（等待时间+业务办理时间）
	//float averageStayTime();

	//按等待时间排序（相同时按到达时间排序）的客户数据输出
	//void waiteTimeRnak();

	//按业务办理时间排序（相同时按到达时间排序）的客户数据输出
	//void serveTimeRank();
private:
	//客户数据集，窗口队列集
	vector<client> datas;
	vector<windowQueue> windows;

	//为客户选择人数最少的窗口，当几个窗口人数一样时选择窗口标号小的窗口
	int BestWindow();

	//当一个新的客户进入银行之前，离开时间小于参数client到达时间的客户出队
	void clientIn(client&);

	//对客户数据根据到达时间进行快排
	void arriveTimeSort(int, int);
};

#endif