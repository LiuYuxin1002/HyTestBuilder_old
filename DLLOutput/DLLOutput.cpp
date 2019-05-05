#include <string>
#include "DLLOutput.h"
#include "TransferClass.h"
#include "ethercat.h"

TransferClass* transfer = new TransferClass();
#ifdef __cplusplus
extern "C"
{
#define TEXPORT extern "C" _declspec(dllexport)
#endif

	TEXPORT int getAdapterNum() {
		return transfer->getAdapterNum();
	}

	TEXPORT int getContextInfo(char* adapterName)
	{
		return transfer->getContextInfo(adapterName);
	}


	TEXPORT int setNicId(int nicId)
	{
		return transfer->setNicId(nicId);
	}


	TEXPORT int initConfig()
	{
		return transfer->initConfig();
	}


	TEXPORT void getSlaveInfo(TransferClass::MySlavet* slave, int id)
	{
		transfer->getSlaveInfo(slave, id);
	}


	TEXPORT int setIntegerValue(int slaveId, int channel, int value)
	{
		return transfer->setIntegerValue(slaveId, channel, value);
	}


	TEXPORT int setDigitValue(int slaveId, int channel, bool value)
	{
		return transfer->setDigitValue(slaveId, channel, value);
	}

#ifdef __cplusplus
}
#endif
