#include "command.h"
#include<iostream>
#include<string>

using namespace::std;

istream& operator>>(istream& is, command& cmd){
	cin.clear();
	cin.sync();
	cout << endl << "myBank> ";
	is >> cmd.cmd;
	return is;
}

void command::welcome(){
	cout << "Welcome to myBank.Command end by pressing enter." << endl;
	cout << "Type 'help' for help." << endl;
}

bool command::begin(){
	return cmd == "begin";
}

bool command::waiteTimeOrder(){
	return cmd == "waiteTimeOrder";
}

bool command::serveTimeOrder(){
	return cmd == "serveTimeOrder";
}

bool command::stayTime(){
	return cmd == "stayTime";
}

bool command::help(){
	return cmd == "help";
}

bool command::quit(){
	return cmd == "quit";
}

void command::uninitInstruction(){
	cout << "warning : bank is not initialized." << endl;
	cout << "try 'begin' to initialize" << endl;
}

void command::helpInstruction(){
	cout << "try command :" << endl;
	cout << "'begin'          for myBank simulation" << endl;
	cout << "'waiteTimeOrder' for myBank ranking by waite time" << endl;
	cout << "'serveTimeOrder' for myBank ranking by serve time" << endl;
	cout << "'stayTime'       for myBank average stay time" << endl;
	cout << "'q' or 'quit'    for myBank quit" << endl;
}

void command::exception(){
	cout << cmd << " is not command for myBank." << endl;
	cout << "try 'help' for help" << endl;
}