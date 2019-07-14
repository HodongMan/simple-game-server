#include "framework.h"
#include <bitset>

#define WORKER_QUEUELENGTH	128 // jobs at max
#define WORKER_THREADS		1

class AuthSessionInfo
{

private:
	sint8				AccountName[15];
	uint32				AccountId;

	uint32				UID1;
	uint32				UID2;
	unsigned long long	uid;
};

