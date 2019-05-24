#include "HiredisHelper.h"

using namespace std;

redisContext* client;

redisContext* getRedisClient() {
	if (client == NULL) {
		client = redisConnect(REDIS_IP, REDIS_PORT);
	}
	
	return client;
}

//private method

int checkRedisError(redisReply* reply) {
	if (reply->type == REDIS_REPLY_ERROR) {
		return -1;
	}
	else {
		return 0;
	}
}

void addKeyValue(char* key, char* value) {
	redisReply* reply = (redisReply*)redisCommand(client, "set %s %s", key, value);
	if (checkRedisError(reply)!=0) {
		printf("出错了");
	}
}

char* getKeyValue(char* key) {
	redisReply* reply = (redisReply*)redisCommand(client, "get %s", key);
	if (checkRedisError(reply) != 0) {
		printf("出错了");
	}
	char* result = reply->str;
	return result;
}

void addKeyValues(char* key, map<char *, char *> value) {
	string cmdstr = "hmset ";
	cmdstr += key;

	map<char*, char*>::iterator it = value.begin();
	while (it != value.end()) {
		cmdstr += " ";
		cmdstr += it->first;
		cmdstr += " ";
		cmdstr += it->second;
		it++;
	}

	redisReply* reply = (redisReply*)redisCommand(client, cmdstr.c_str());
	
	if (checkRedisError(reply) != 0) {
		printf("出错了");
	}
}

map<char*, char*> getKeyValues(char* key) {
	string cmdstr = "hmget ";
	cmdstr += key;
	redisReply* reply = (redisReply*)redisCommand(client, cmdstr.c_str());

	map<char*, char*>* resultMap = new map<char *, char *>();

	int resultNum = reply->elements;
	for (int i = 0; i < resultNum;) {
		char* fieldstr = reply->element[i++]->str;
		char* valuestr = reply->element[i++]->str;
		resultMap->insert(pair<char*, char*>(fieldstr, valuestr));
	}
	return *resultMap;
}


