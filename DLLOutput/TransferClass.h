#pragma once

#include <string>
#include "ethercat.h"

using namespace std;

public class TransferClass
{
public:
	TransferClass();

	/*声明传递信息所用结构体：nic, slave, ec...*/
	struct context{
		string* nicInfo;
		int nicNum;
		int nicSelected;
		int slaveNum;
	};
	typedef context *ptrToContext;

	//获取计算机网卡信息
	int getContextInfo(context* targetContext);
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

