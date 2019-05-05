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
#define MAX_SLAVE 1000

	#pragma region ��վ������Ϣ
	struct DI2
	{
		bool values[2];
		DI2* next = NULL;
	};
	struct DI4
	{
		bool values[4];
		DI4* next = NULL;
	};
	struct DI8
	{
		bool values[8];
		DI8* next = NULL;
	};
	struct DO2
	{
		bool values[2];
		DO2* next = NULL;
	};
	struct DO4
	{
		bool values[4];
		DO4* next = NULL;
	};
	struct DO8
	{
		bool values[8];
		DO8* next = NULL;
	};
	struct AI1
	{
		int16 values[1];
		AI1* next = NULL;
	};
	struct AI2
	{
		int16 values[2];
		AI2* next = NULL;
	};
	struct AI4
	{
		int16 values[4];
		AI4* next = NULL;
	};
	struct AI8
	{
		int16 values[8];
		AI8* next = NULL;
	};
	struct AO1
	{
		int16 values[1];
		AO1* next = NULL;
	};
	struct AO2
	{
		int16 values[2];
		AO2* next = NULL;
	};
	struct AO4
	{
		int16 values[4];
		AO4* next = NULL;
	};
	struct AO8
	{
		int16 values[8];
		AO8* next;
	};

	typedef struct DI2 *slave_di2;
	typedef struct DI4 *slave_di4;
	typedef struct DI8 *slave_di8;
	typedef struct DO2 *slave_do2;
	typedef struct DO4 *slave_do4;
	typedef struct DO8 *slave_do8;
	typedef struct AI1 *slave_ai1;
	typedef struct AI2 *slave_ai2;
	typedef struct AI4 *slave_ai4;
	typedef struct AI8 *slave_ai8;
	typedef struct AO1 *slave_ao1;
	typedef struct AO2 *slave_ao2;
	typedef struct AO4 *slave_ao4;
	typedef struct AO8 *slave_ao8;
	#pragma endregion

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
	
	slave_di2 di2 = (slave_di2)new DI2();
	slave_di4 di4 = (slave_di4)new DI4();
	slave_di8 di8 = (slave_di8)new DI8();
	slave_do2 do2 = (slave_do2)new DO2();
	slave_do4 do4 = (slave_do4)new DO4();
	slave_do8 do8 = (slave_do8)new DO8();
	slave_ai1 ai1 = (slave_ai1)new AI1();
	slave_ai2 ai2 = (slave_ai2)new AI2();
	slave_ai4 ai4 = (slave_ai4)new AI4();
	slave_ai8 ai8 = (slave_ai8)new AI8();
	slave_ao1 ao1 = (slave_ao1)new AO1();
	slave_ao2 ao2 = (slave_ao2)new AO2();
	slave_ao4 ao4 = (slave_ao4)new AO4();
	slave_ao8 ao8 = (slave_ao8)new AO8();

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
	struct MySlavet {
		void* ptrToSlave;	//ָ���Ӧ�Ĵ�վ�˿�
		char* name;			//�ɶ�����
		int type;			//0:empty, 1:di, 2:do, 3:ai, 4:ao
		int channelNum;		//1,2,4,8...Ŀǰ����ֻ֧��������
	} my_slave[MAX_SLAVE];



	//��ȡ�����������Ϣ
	int getAdapterNum();
	int getContextInfo(char* adapterName);
	//��������,���ش�վ��Ŀ
	int setNicId(int nicId);
	//�Զ����ô�վ
	int initConfig();
	//�������ú�Ĵ�վ��Ϣ
	void getSlaveInfo(MySlavet* slave, int id);
	//���ô�վ�˿�ֵ
	int setIntegerValue(int slaveId, int channel, int value);
	int setDigitValue(int slaveId, int channel, bool value);

private:
	int initSlaveInfo(char* ifname);
	

};

