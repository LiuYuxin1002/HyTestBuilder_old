// 这是主 DLL 文件。
#include "mycontext.h"


//SoemImplClass* transfer = new SoemImplClass();
#ifdef __cplusplus
extern "C"
{
#define TEXPORT extern "C" _declspec(dllexport)
#else
#define TEXPORT _declspec(dllexport)
#endif


	TEXPORT int getAdapterNum() {
		return getAdapterNumImpl();
	}

	TEXPORT int getContextInfo(char* adapterName)
	{
		return getContextInfoImpl(adapterName);
	}


	TEXPORT int setNicId(int nicId)
	{
		return setNicIdImpl(nicId);
	}


	TEXPORT int initConfig()
	{
		return initConfigImpl();
	}

	TEXPORT void getSlaveInfo(void* slave, int id)
	{
		getSlaveInfoImpl();
	}


	TEXPORT int setIntegerValue(int slaveId, int channel, int value)
	{
		return setIntegerValueImpl(slaveId, channel, value);
	}


	TEXPORT int setBoolValue(int slaveId, int channel, boolean value)
	{
		return setBoolValueImpl(slaveId, channel, value);
	}

#ifdef __cplusplus
}
#endif




