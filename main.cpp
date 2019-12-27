#include "myBank.h"
#include "command.h"

using namespace::std;

int main()
{
	//command���������bank�����ж���
	command cmd;
	myBank bank;
	
	//��ӭ���
	cmd.welcome();

	//�û����棬���Դ�������ģ�⣬�ȴ�ʱ��ͷ���ʱ�����򣬼��㶺��ʱ�䣬������δ��ʼ�������Լ��˳�
	while (true){
		//��������
		cin >> cmd;

		//��ʼ��bank���󣬲���ģ����Ŷӵ����
		if (cmd.begin()){
			bank.myBankSimulation();
		}

		//���ݵȴ�ʱ���bank���������������
		else if (cmd.waiteTimeOrder()){
			if (bank.initFinished()){
				bank.waiteTimeRank();
			}
			else{
				//��ʾδ��ʼ��
				cmd.uninitInstruction();
			}
		}

		//���ݷ���ʱ���bank���������������
		else if (cmd.serveTimeOrder()){
			if (bank.initFinished()){
				bank.serveTimeRank();
			}
			else{
				//��ʾδ��ʼ��
				cmd.uninitInstruction();
			}
		}

		//����bank���������Ԫ�ص�ƽ������ʱ��
		else if (cmd.stayTime()){
			if (bank.initFinished()){
				bank.averageStayTime();
			}
			else{
				//��ʾδ��ʼ��
				cmd.uninitInstruction();
			}
		}

		//������ʾ
		else if (cmd.help()){
			cmd.helpInstruction();
		}

		//�˳�����
		else if (cmd.quit()){
			break;
		}

		//���������ʾ
		else{
			cmd.exception();
		}
	}

	return 0;
}