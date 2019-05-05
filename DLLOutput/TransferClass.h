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

	//全局变量
	char IOmap[4096];
	OSAL_THREAD_HANDLE thread1;
	int expectedWKC;
	boolean needlf;
	volatile int wkc;
	boolean inOP;
	uint8 currentgroup = 0;
	//用于获取从站信息的全局变量
	ec_adaptert* adapter;


	/*声明传递信息所用结构体：nic, slave, ec...*/
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

	//获取计算机网卡信息
	int getAdapterNum();
	int getContextInfo(char* adapterName);
	//设置网卡,返回从站数目
	int setNicId(int nicId);
	//自动配置从站
	int initConfig();
	//返回配置后的从站信息
	void getSlaveInfo(ec_slavet* slave, int id);
	//设置从站端口值
	int setIntegerValue(int slaveId, int channel, int value);
	int setDoubleValue(int slaveId, int channel, double value);

};

