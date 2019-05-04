#pragma once

#include <string>
#include "ethercat.h"

using namespace std;

public class TransferClass
{
public:
	TransferClass();

	/*����������Ϣ���ýṹ�壺nic, slave, ec...*/
	struct context{
		string* nicInfo;
		int nicNum;
		int nicSelected;
		int slaveNum;
	};
	typedef context *ptrToContext;

	//��ȡ�����������Ϣ
	int getContextInfo(context* targetContext);
	//��������,���ش�վ��Ŀ
	int setNicId(int nicId);
	//�Զ����ô�վ
	int initConfig();
	//�������ú�Ĵ�վ��Ϣ
	void getSlaveInfo(ec_slavet* slave, int id);
	//���ô�վ�˿�ֵ
	int setIntegerValue(int slaveId, int channel, int value);
	int setDoubleValue(int slaveId, int channel, double value);

};

