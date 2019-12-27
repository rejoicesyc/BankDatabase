#include "myBank.h"
#include "command.h"

using namespace::std;

int main()
{
	//command是命令对象，bank是银行对象
	command cmd;
	myBank bank;
	
	//欢迎语句
	cmd.welcome();

	//用户界面，可以处理银行模拟，等待时间和服务时间排序，计算逗留时间，帮助，未初始化处理以及退出
	while (true){
		//输入命令
		cin >> cmd;

		//初始化bank对象，并且模拟出排队的情况
		if (cmd.begin()){
			bank.myBankSimulation();
		}

		//根据等待时间对bank对象进行排序和输出
		else if (cmd.waiteTimeOrder()){
			if (bank.initFinished()){
				bank.waiteTimeRank();
			}
			else{
				//提示未初始化
				cmd.uninitInstruction();
			}
		}

		//根据服务时间对bank对象进行排序和输出
		else if (cmd.serveTimeOrder()){
			if (bank.initFinished()){
				bank.serveTimeRank();
			}
			else{
				//提示未初始化
				cmd.uninitInstruction();
			}
		}

		//计算bank对象的所有元素的平均逗留时间
		else if (cmd.stayTime()){
			if (bank.initFinished()){
				bank.averageStayTime();
			}
			else{
				//提示未初始化
				cmd.uninitInstruction();
			}
		}

		//命令提示
		else if (cmd.help()){
			cmd.helpInstruction();
		}

		//退出程序
		else if (cmd.quit()){
			break;
		}

		//命令错误提示
		else{
			cmd.exception();
		}
	}

	return 0;
}