#include "defineValues.h"
#include "myBank.h"
#include "client.h"
#include "windowQueue.h"
#include<cstdlib>
#include<ctime>

using namespace::std;

myBank::myBank(){
	flag = false;
}

void myBank::myBankSimulation(){
	datas.resize(0);
	windows.resize(windowNums);

	srand((unsigned)time(NULL));
	for (int i = 0; i < clientNums; i++){
		client c;
		datas.push_back(c);
	}

	arriveTimeSort(0, clientNums - 1);
	for (int i = 0; i < clientNums; i++){
		clientIn(datas[i]);
	}
	flag = true;

	cout << "  arriveTime  departureTime  serveTime  waiteTime  windowNum" << endl;
	for (int i = 0; i < clientNums; i++){
		cout << datas[i];
	}
}

void myBank::averageStayTime(){
	float result = 0.0;
	for (int i = 0; i < clientNums; i++){
		result += (float)datas[i].stayTimetoMinute();
	}
	cout << "styTime = " << result / (float)clientNums << endl;
}

void myBank::waiteTimeRank(){
	waiteTimeSort(0, clientNums - 1);

	cout << "  arriveTime  departureTime  serveTime  waiteTime  windowNum" << endl;
	for (int i = 0; i < clientNums; i++){
		cout << datas[i];
	}
}

void myBank::serveTimeRank(){
	serveTimeSort(0, clientNums - 1);

	cout << "  arriveTime  departureTime  serveTime  waiteTime  windowNum" << endl;
	for (int i = 0; i < clientNums; i++){
		cout << datas[i];
	}
}

bool myBank::initFinished() const{
	return flag;
}

int myBank::BestWindow(){
	int window, Min = INT_MAX;
	for (int i = 0; i < windowNums; i++){
		if (windows[i].size() < Min){
			window = i;
			Min = windows[i].size();
		}
	}
	return window;
}

void myBank::clientIn(client& c){
	for (int i = 0; i < windowNums; i++){
		while (!windows[i].empty() && leaveBeforeArrive(windows[i].front(), c)){
			windows[i].pop();
		}
	}
	int window = BestWindow();
	windows[window].push(c,window);
}

void myBank::arriveTimeSort(int l, int r){
	if (l >= r){
		return;
	}
	int i = l, j = r;
	client key = datas[i];
	while (i < j){
		while (i < j&&arriveTimePrior(key, datas[j])){
			j--;
		}
		datas[i] = datas[j];
		while (i < j&&arriveTimePriorEqual(datas[i], key)){
			i++;
		}
		datas[j] = datas[i];
	}
	datas[i] = key;
	arriveTimeSort(l, i - 1);
	arriveTimeSort(i + 1, r);
}

void myBank::waiteTimeSort(int l, int r){
	if (l >= r){
		return;
	}
	int i = l, j = r;
	client key = datas[i];
	while (i < j){
		while (i < j&&waiteTimePrior(key, datas[j])){
			j--;
		}
		datas[i] = datas[j];
		while (i < j&&waiteTimePrior(datas[i], key)){
			i++;
		}
		datas[j] = datas[i];
	}
	datas[i] = key;
	waiteTimeSort(l, i - 1);
	waiteTimeSort(i + 1, r);
}

void myBank::serveTimeSort(int l, int r){
	if (l >= r){
		return;
	}
	int i = l, j = r;
	client key = datas[i];
	while (i < j){
		while (i < j&&serveTimePrior(key, datas[j])){
			j--;
		}
		datas[i] = datas[j];
		while (i < j&&serveTimePrior(datas[i], key)){
			i++;
		}
		datas[j] = datas[i];
	}
	datas[i] = key;
	serveTimeSort(l, i - 1);
	serveTimeSort(i + 1, r);
}