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

		/*di2 = (slave_di2)new DI2();
		di4 = (slave_di4)new DI4();
		di8 = (slave_di8)new DI8();
		do2 = (slave_do2)new DO2();*/
	}


	char IOmap[4096];
	int TransferClass::initSlaveInfo(char* ifname) {
		int cnt, i, j, nSM;
		uint16 ssigen;
		int expectedWKC;

		printf("Starting slaveinfo\n");

		/* initialise SOEM, bind socket to ifname */
		if (ec_init(ifname))
		{
			printf("ec_init on %s succeeded.\n", ifname);
			/* find and auto-config slaves */
			if (ec_config(FALSE, &IOmap) > 0)
			{
				ec_configdc();
				while (EcatError) printf("%s", ec_elist2string());
				printf("%d slaves found and configured.\n", ec_slavecount);
				expectedWKC = (ec_group[0].outputsWKC * 2) + ec_group[0].inputsWKC;
				printf("Calculated workcounter %d\n", expectedWKC);
				/* wait for all slaves to reach SAFE_OP state */
				ec_statecheck(0, EC_STATE_SAFE_OP, EC_TIMEOUTSTATE * 3);
				if (ec_slave[0].state != EC_STATE_SAFE_OP)
				{
					printf("Not all slaves reached safe operational state.\n");
					ec_readstate();
					for (i = 1; i <= ec_slavecount; i++)
					{
						if (ec_slave[i].state != EC_STATE_SAFE_OP)
						{
							printf("Slave %d State=%2x StatusCode=%4x : %s\n",
								i, ec_slave[i].state, ec_slave[i].ALstatuscode, ec_ALstatuscode2string(ec_slave[i].ALstatuscode));
						}
					}
				}
				ec_readstate();
				//打印从站具体信息
				//for (cnt = 1; cnt <= ec_slavecount; cnt++)
				//{
				//	printf("\nSlave:%d\n Name:%s\n Output size: %dbits\n Input size: %dbits\n State: %d\n Delay: %d[ns]\n Has DC: %d\n",
				//		cnt, ec_slave[cnt].name, ec_slave[cnt].Obits, ec_slave[cnt].Ibits,
				//		ec_slave[cnt].state, ec_slave[cnt].pdelay, ec_slave[cnt].hasdc);
				//	if (ec_slave[cnt].hasdc) printf(" DCParentport:%d\n", ec_slave[cnt].parentport);
				//	printf(" Activeports:%d.%d.%d.%d\n", (ec_slave[cnt].activeports & 0x01) > 0,
				//		(ec_slave[cnt].activeports & 0x02) > 0,
				//		(ec_slave[cnt].activeports & 0x04) > 0,
				//		(ec_slave[cnt].activeports & 0x08) > 0);
				//	printf(" Configured address: %4.4x\n", ec_slave[cnt].configadr);
				//	printf(" Man: %8.8x ID: %8.8x Rev: %8.8x\n", (int)ec_slave[cnt].eep_man, (int)ec_slave[cnt].eep_id, (int)ec_slave[cnt].eep_rev);
				//	for (nSM = 0; nSM < EC_MAXSM; nSM++)
				//	{
				//		if (ec_slave[cnt].SM[nSM].StartAddr > 0)
				//			printf(" SM%1d A:%4.4x L:%4d F:%8.8x Type:%d\n", nSM, ec_slave[cnt].SM[nSM].StartAddr, ec_slave[cnt].SM[nSM].SMlength,
				//			(int)ec_slave[cnt].SM[nSM].SMflags, ec_slave[cnt].SMtype[nSM]);
				//	}
				//	for (j = 0; j < ec_slave[cnt].FMMUunused; j++)
				//	{
				//		printf(" FMMU%1d Ls:%8.8x Ll:%4d Lsb:%d Leb:%d Ps:%4.4x Psb:%d Ty:%2.2x Act:%2.2x\n", j,
				//			(int)ec_slave[cnt].FMMU[j].LogStart, ec_slave[cnt].FMMU[j].LogLength, ec_slave[cnt].FMMU[j].LogStartbit,
				//			ec_slave[cnt].FMMU[j].LogEndbit, ec_slave[cnt].FMMU[j].PhysStart, ec_slave[cnt].FMMU[j].PhysStartBit,
				//			ec_slave[cnt].FMMU[j].FMMUtype, ec_slave[cnt].FMMU[j].FMMUactive);
				//	}
				//	printf(" FMMUfunc 0:%d 1:%d 2:%d 3:%d\n",
				//		ec_slave[cnt].FMMU0func, ec_slave[cnt].FMMU1func, ec_slave[cnt].FMMU2func, ec_slave[cnt].FMMU3func);
				//	printf(" MBX length wr: %d rd: %d MBX protocols : %2.2x\n", ec_slave[cnt].mbx_l, ec_slave[cnt].mbx_rl, ec_slave[cnt].mbx_proto);
				//	ssigen = ec_siifind(cnt, ECT_SII_GENERAL);
				//	/* SII general section */
				//	if (ssigen)
				//	{
				//		ec_slave[cnt].CoEdetails = ec_siigetbyte(cnt, ssigen + 0x07);
				//		ec_slave[cnt].FoEdetails = ec_siigetbyte(cnt, ssigen + 0x08);
				//		ec_slave[cnt].EoEdetails = ec_siigetbyte(cnt, ssigen + 0x09);
				//		ec_slave[cnt].SoEdetails = ec_siigetbyte(cnt, ssigen + 0x0a);
				//		if ((ec_siigetbyte(cnt, ssigen + 0x0d) & 0x02) > 0)
				//		{
				//			ec_slave[cnt].blockLRW = 1;
				//			ec_slave[0].blockLRW++;
				//		}
				//		ec_slave[cnt].Ebuscurrent = ec_siigetbyte(cnt, ssigen + 0x0e);
				//		ec_slave[cnt].Ebuscurrent += ec_siigetbyte(cnt, ssigen + 0x0f) << 8;
				//		ec_slave[0].Ebuscurrent += ec_slave[cnt].Ebuscurrent;
				//	}
				//	printf(" CoE details: %2.2x FoE details: %2.2x EoE details: %2.2x SoE details: %2.2x\n",
				//		ec_slave[cnt].CoEdetails, ec_slave[cnt].FoEdetails, ec_slave[cnt].EoEdetails, ec_slave[cnt].SoEdetails);
				//	printf(" Ebus current: %d[mA]\n only LRD/LWR:%d\n",
				//		ec_slave[cnt].Ebuscurrent, ec_slave[cnt].blockLRW);
				//	if ((ec_slave[cnt].mbx_proto & ECT_MBXPROT_COE) && printSDO)
				//		si_sdo(cnt);
				//	if (printMAP)
				//	{
				//		if (ec_slave[cnt].mbx_proto & ECT_MBXPROT_COE)
				//			si_map_sdo(cnt);
				//		else
				//			si_map_sii(cnt);
				//	}
				//}
				return ec_slavecount;
			}
			else
			{
				printf("No slaves found!\n");
				return 0;
			}
			printf("End slaveinfo, close socket\n");
			/* stop SOEM, close socket */
			//ec_close();
		}
		else
		{
			printf("No socket connection on %s\nExcecute as root\n", ifname);
			return -1;
		}
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
		return 0;
	}

	char ifbuf[1024];
	int TransferClass::setNicId(int nicId) {
		//if ((argc > 2) && (strncmp(argv[2], "-sdo", sizeof("-sdo")) == 0)) printSDO = TRUE;
		//if ((argc > 2) && (strncmp(argv[2], "-map", sizeof("-map")) == 0)) printMAP = TRUE;
		/* start slaveinfo */
		//printf(myadapter.nicName[nicId].data());发现了所选和所见对应不上
		char* completeStr = strcat("\\Device\\NPF_", myadapter.nicName[nicId].data());
		strcpy(ifbuf, completeStr);
		
		return initSlaveInfo(ifbuf);;
	}

	int TransferClass::initConfig() {
		return 0;
	}

	void TransferClass::getSlaveInfo(MySlavet* slave, int id) {
		if (ec_slavecount == 0) return;

		for (int i = 0; i < ec_slavecount; i++) {
			if (i == 0) {
				continue;
			}

			char* name = ec_slave[i].name;
			int type = name[2] - '0';
			int channel = name[5] - '0';

			//判断从站类型
			switch (type)
			{
			case 1://DI
			{
				//判断端口数量
				switch (channel)
				{
				case 2:
				{
					slave_di2 tmpslave = (slave_di2)malloc(sizeof(DI2));
					tmpslave = (slave_di2)ec_slave[i].outputs;

					slave_di2 ptr = di2->next;
					di2->next = tmpslave;
					tmpslave->next = ptr;

					my_slave[i].ptrToSlave = tmpslave;
				}
					break;
				case 4:
				{
					slave_di4 tmpslave = (slave_di4)malloc(sizeof(DI4));
					tmpslave = (slave_di4)ec_slave[i].outputs;

					slave_di4 ptr = di4->next;
					di4->next = tmpslave;
					tmpslave->next = ptr;

					my_slave[i].ptrToSlave = tmpslave;
					break;
				}
				case 8: {
					slave_di8 tmpslave = (slave_di8)malloc(sizeof(DI8));
					tmpslave = (slave_di8)ec_slave[i].outputs;

					slave_di8 ptr = di8->next;
					di8->next = tmpslave;
					tmpslave->next = ptr;

					my_slave[i].ptrToSlave = tmpslave;
					break;
				}
				default:
					break;
				}
			}
			case 2://DO
			{
				switch (channel)
				{
				case 2:

				case 4:

				case 8:

				default:
					break;
				}
				break;
			}
			case 3://AI
			{
				switch (channel)
				{
				case 1:

				case 2:

				case 4:

				case 8:

				default:
					break;
				}
				break;
			}
			case 4://AO
			{
				switch (channel)
				{
				case 1:

				case 2:

				case 4:

				case 8:

				default:
					break;
				}
				break;
			}
			default:
				break;
			}

			my_slave[i].name = name;
			my_slave[i].type = type;
			my_slave[i].channelNum = channel;
		}
	}

	int TransferClass::setIntegerValue(int slaveId, int channel, int value) {
		MySlavet* slave = &my_slave[slaveId];
		int type = slave->type;
		
		if (channel > slave->channelNum) {	//没那么多端口
			printf("没那么多端口，检查channel的值\n");
			return -1;
		}
		else if (type != 4) {				//设置模拟量只能是模拟量输出
			printf("设置模拟量只能是模拟量输出，检查slaveId的值\n");
			return -2;
		}
		else {
			switch (slave->channelNum)
			{
			case 1: {
				slave_ao1 tmp = (slave_ao1)slave->ptrToSlave;
				tmp->values[channel] = value;
			}
			case 2: {
				slave_ao2 tmp = (slave_ao2)slave->ptrToSlave;
				tmp->values[channel] = value;
			}
			case 4: {
				slave_ao4 tmp = (slave_ao4)slave->ptrToSlave;
				tmp->values[channel] = value;
			}
			case 8: {
				slave_ao8 tmp = (slave_ao8)slave->ptrToSlave;
				tmp->values[channel] = value;
			}
			default:
				break;
			}
		}
		return 0;
	}

	int TransferClass::setDigitValue(int slaveId, int channel, bool value) {
		MySlavet* slave = &my_slave[slaveId];
		int type = slave->type;
		
		if (channel > slave->channelNum) {//没那么多端口
			printf("没那么多端口，检查channel的值\n");
			return -1;
		}
		else if (type != 2) {				//设置数字量只能是数字量输出
			printf("设置数字量只能是数字量输出，检查slaveId的值\n");
			return -2;
		}
		else {
			switch (slave->channelNum)
			{
			case 2: {
				slave_do2 tmp = (slave_do2)slave->ptrToSlave;
				tmp->values[channel] = value;
			}
			case 4: {
				slave_do4 tmp = (slave_do4)slave->ptrToSlave;
				tmp->values[channel] = value;
			}
			case 8: {
				slave_do8 tmp = (slave_do8)slave->ptrToSlave;
				tmp->values[channel] = value;
			}
			default:
				break;
			}
		}
		return 0;
	}


#ifdef __cplusplus
}
#endif