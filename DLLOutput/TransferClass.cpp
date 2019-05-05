#include "TransferClass.h"

#ifdef __cplusplus
extern "C"
{
#endif

	TransferClass::TransferClass()
	{
		printf("SOEM主站开始工作...\n");
		adapter = NULL;//网络适配器置空
		//myadapter = *new adaptert();
		//创立监控线程
		//osal_thread_create(&thread1, EC_STACK_SIZE, &ecatcheck, (void*)&ctime);
	}

	int TransferClass::getAdapterNum() {
		myadapter.adapterNum = 0;
		adapter = ec_find_adapters();
		while (adapter != NULL) {
			myadapter.nicDesc.push_back(adapter->desc);
			myadapter.nicName.push_back(adapter->name);
			adapter = adapter->next;
			myadapter.adapterNum++;
		}
		return myadapter.adapterNum;
	}

	int TransferClass::getContextInfo(char* adapterName) {
		if (myadapter.adapterNum > 0) {
			strcpy(adapterName, (char*)myadapter.nicName[--myadapter.adapterNum].data());
		}
		return myadapter.adapterNum;
	}

	int TransferClass::setNicId(int nicId) {
		return 0;
	}

	int TransferClass::initConfig() {
		return 0;
	}

	void TransferClass::getSlaveInfo(ec_slavet* slave, int id) {

	}

	int TransferClass::setIntegerValue(int slaveId, int channel, int value) {
		return 0;
	}

	int TransferClass::setDoubleValue(int slaveId, int channel, double value) {
		return 0;
	}

#ifdef __cplusplus
}
#endif