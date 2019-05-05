#pragma once

#include <string>
#include <inttypes.h>
#include <stdio.h>
#include "ethercat.h"
#include <iostream>
#include <vector>


using namespace std;

public class TransferClass
{
public:
	TransferClass();


#define EC_TIMEOUT 500
#define EC_STACK_SIZE 128000

	//ȫ�ֱ���
	char IOmap[4096];
	OSAL_THREAD_HANDLE thread1;
	int expectedWKC;
	boolean needlf;
	volatile int wkc;
	boolean inOP;
	uint8 currentgroup = 0;
	//���ڻ�ȡ��վ��Ϣ��ȫ�ֱ���
	ec_adaptert* adapter;


	/*����������Ϣ���ýṹ�壺nic, slave, ec...*/
	typedef struct adaptert *ptrToAdapter;
	struct adaptert{
		vector<string> nicDesc;
		vector<string> nicName;
		int adapterNum;
	} myadapter;
	struct MyContext {
		int nicSelected;
		int slaveNum;
	};

	//��ȡ�����������Ϣ
	int getAdapterNum();
	int getContextInfo(char* adapterName);
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

