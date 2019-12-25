#include "defineValues.h"
#include "myBank.h"
#include "client.h"
#include "windowQueue.h"
#include<cstdlib>
#include<ctime>

using namespace::std;

myBank::myBank(){
	windows.resize(windowNums);
	srand((unsigned)time(NULL));
	for (int i = 0; i < clientNums; i++){
		client c;
		datas.push_back(c);
	}
}

void myBank::myBankSimulation(){
	arriveTimeSort(0, clientNums - 1);
	for (int i = 0; i < clientNums; i++){
		clientIn(datas[i]);
	}
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