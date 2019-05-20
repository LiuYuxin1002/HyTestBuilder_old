#pragma once
#include<hash_map>
#include <stdio.h>
#include <stdlib.h>
#include<string>
#include"SoemImplClass.h"

#include <hiredis.h>
#include <win32fixes.h>

using namespace std;

class  Trans2Redis
{
public:
	Trans2Redis();

	hash_map<string, string> TIME;
	
	SoemImplClass::MySlavet SoemImplClass::my_slave[MAX_SLAVE];

	//void slave2Hash( int slaveNum);
	void slave2Hash();

	void hash2Redis(hash_map<string, string> hashmap);

private:

};