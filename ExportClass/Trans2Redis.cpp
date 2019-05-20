#include"Trans2Redis.h"

#ifdef __cplusplus
extern "C"
{
#endif



	void Trans2Redis::slave2Hash()
	{
		for (int i = 0; i < ec_slavecount; i++)
		{
			//判断

#pragma region
			//判断从站类型
			switch (my_slave[i].type)
			{
			case 1://DI
			{
					   //判断端口数量
					   switch (my_slave[i].channelNum)
					   {
					   case 2:
					   {
								 for (int j = 0; j < my_slave[i].channelNum; j++)
								 {
									 string KEY = to_string(i) + "_" + to_string(j);//slave id_channal id									 
									 int VALUE_temp = (int)(*((slave_di2)my_slave[i].ptrToSlave)->values + j);

									 string VALUE = to_string(VALUE_temp);

									 TIME.insert(pair<string, string>(KEY, VALUE));
								 }
								 break;
					   }

					   case 4:
					   {
								 for (int j = 0; j < my_slave[i].channelNum; j++)
								 {
									 string KEY = to_string(i) + "_" + to_string(j);//slave id_channal id									 
									 int VALUE_temp = (int)(*((slave_di4)my_slave[i].ptrToSlave)->values + j);

									 string VALUE = to_string(VALUE_temp);

									 TIME.insert(pair<string, string>(KEY, VALUE));
								 }
								 break;
					   }
					   case 8: {
								   for (int j = 0; j < my_slave[i].channelNum; j++)
								   {
									   string KEY = to_string(i) + "_" + to_string(j);//slave id_channal id									 
									   int VALUE_temp = (int)(*((slave_di8)my_slave[i].ptrToSlave)->values + j);

									   string VALUE = to_string(VALUE_temp);

									   TIME.insert(pair<string, string>(KEY, VALUE));
								   }
								   break;
					   }
					   default:
						   break;
					   }
			}
			case 2://DO
			{
					   switch (my_slave[i].channelNum)
					   {
					   case 2:
					   {
								 for (int j = 0; j < my_slave[i].channelNum; j++)
								 {
									 string KEY = to_string(i) + "_" + to_string(j);//slave id_channal id									 
									 int VALUE_temp = (int)(*((slave_do2)my_slave[i].ptrToSlave)->values + j);

									 string VALUE = to_string(VALUE_temp);

									 TIME.insert(pair<string, string>(KEY, VALUE));
								 }
								 break;

					   }

					   case 4:
					   {
								 for (int j = 0; j < my_slave[i].channelNum; j++)
								 {
									 string KEY = to_string(i) + "_" + to_string(j);//slave id_channal id									 
									 int VALUE_temp = (int)(*((slave_do4)my_slave[i].ptrToSlave)->values + j);

									 string VALUE = to_string(VALUE_temp);

									 TIME.insert(pair<string, string>(KEY, VALUE));
								 }
								 break;

					   }


					   case 8:
					   {
								 for (int j = 0; j < my_slave[i].channelNum; j++)
								 {
									 string KEY = to_string(i) + "_" + to_string(j);//slave id_channal id									 
									 int VALUE_temp = (int)(*((slave_do8)my_slave[i].ptrToSlave)->values + j);

									 string VALUE = to_string(VALUE_temp);

									 TIME.insert(pair<string, string>(KEY, VALUE));
								 }
								 break;

					   }



					   default:
						   break;
					   }
					   break;
			}
			case 3://AI
			{
					   switch (my_slave[i].channelNum)
					   {
					   case 1:
					   {
								 for (int j = 0; j < my_slave[i].channelNum; j++)
								 {
									 string KEY = to_string(i) + "_" + to_string(j);//slave id_channal id									 
									 int VALUE_temp = (int)(*((slave_ai1)my_slave[i].ptrToSlave)->values + j);

									 string VALUE = to_string(VALUE_temp);

									 TIME.insert(pair<string, string>(KEY, VALUE));
								 }
								 break;

					   }



					   case 2:
					   {
								 for (int j = 0; j < my_slave[i].channelNum; j++)
								 {
									 string KEY = to_string(i) + "_" + to_string(j);//slave id_channal id									 
									 int VALUE_temp = (int)(*((slave_ai2)my_slave[i].ptrToSlave)->values + j);

									 string VALUE = to_string(VALUE_temp);

									 TIME.insert(pair<string, string>(KEY, VALUE));
								 }
								 break;

					   }

					   case 4:
					   {
								 for (int j = 0; j < my_slave[i].channelNum; j++)
								 {
									 string KEY = to_string(i) + "_" + to_string(j);//slave id_channal id									 
									 int VALUE_temp = (int)(*((slave_ai4)my_slave[i].ptrToSlave)->values + j);

									 string VALUE = to_string(VALUE_temp);

									 TIME.insert(pair<string, string>(KEY, VALUE));
								 }
								 break;

					   }

					   case 8:
					   {
								 for (int j = 0; j < my_slave[i].channelNum; j++)
								 {
									 string KEY = to_string(i) + "_" + to_string(j);//slave id_channal id									 
									 int VALUE_temp = (int)(*((slave_ai8)my_slave[i].ptrToSlave)->values + j);

									 string VALUE = to_string(VALUE_temp);

									 TIME.insert(pair<string, string>(KEY, VALUE));
								 }
								 break;

					   }

					   default:
						   break;
					   }
					   break;
			}
			case 4://AO
			{
					   switch (my_slave[i].channelNum)
					   {
					   case 1:
					   {
								 for (int j = 0; j < my_slave[i].channelNum; j++)
								 {
									 string KEY = to_string(i) + "_" + to_string(j);//slave id_channal id									 
									 int VALUE_temp = (int)(*((slave_ao1)my_slave[i].ptrToSlave)->values + j);

									 string VALUE = to_string(VALUE_temp);

									 TIME.insert(pair<string, string>(KEY, VALUE));
								 }
								 break;

					   }

					   case 2:
					   {
								 for (int j = 0; j < my_slave[i].channelNum; j++)
								 {
									 string KEY = to_string(i) + "_" + to_string(j);//slave id_channal id									 
									 int VALUE_temp = (int)(*((slave_ao2)my_slave[i].ptrToSlave)->values + j);

									 string VALUE = to_string(VALUE_temp);

									 TIME.insert(pair<string, string>(KEY, VALUE));
								 }
								 break;

					   }



					   case 4:
					   {
								 for (int j = 0; j < my_slave[i].channelNum; j++)
								 {
									 string KEY = to_string(i) + "_" + to_string(j);//slave id_channal id									 
									 int VALUE_temp = (int)(*((slave_ao4)my_slave[i].ptrToSlave)->values + j);

									 string VALUE = to_string(VALUE_temp);

									 TIME.insert(pair<string, string>(KEY, VALUE));
								 }
								 break;

					   }



					   case 8:
					   {
								 for (int j = 0; j < my_slave[i].channelNum; j++)
								 {
									 string KEY = to_string(i) + "_" + to_string(j);//slave id_channal id									 
									 int VALUE_temp = (int)(*((slave_ao8)my_slave[i].ptrToSlave)->values + j);

									 string VALUE = to_string(VALUE_temp);

									 TIME.insert(pair<string, string>(KEY, VALUE));
								 }
								 break;

					   }


					   default:
						   break;
					   }
					   break;
			}
			default:
				break;
			}
#pragma endregion

		}
	}

	void Trans2Redis::hash2Redis(hash_map<string, string> hashmap)
	{
		redisContext*c = redisConnect("127.0.0.1", 6379);
		if (c->err)
		{
			redisFree(c);
			return;
		}

		for (hash_map<string, string>::iterator i = hashmap.begin(); i != hashmap.end(); i++)
		{
			redisReply* r = (redisReply*)redisCommand(c, "HSET TransHash %s %s", i->first, i->second);
			freeReplyObject(r);
		}
	}

#ifdef __cplusplus
}
#endif