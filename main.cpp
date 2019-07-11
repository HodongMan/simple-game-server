#include "pch.h"

SOCKET hQueuePort;
SOCKET hGamePort;

SOCKET createSocket( uint16 port ) noexcept
{
	SOCKET s = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
	SOCKADDR_IN addr;
	memset( &addr, 0, sizeof( SOCKADDR_IN ) );

	addr.sin_family			= AF_INET;
	addr.sin_port			= htons( port );
	addr.sin_addr.s_addr	= ADDR_ANY;

	if ( SOCKET_ERROR == bind( s, (SOCKADDR*)&addr, sizeof( SOCKADDR_IN ) ) )
	{
		closesocket( s );

		return SOCKET_ERROR;
	}

	listen( s, 16 );

	return s;
}

typedef struct
{
	SOCKET		socket;
	uint8		RecvBuffer[128];
	uint32		RecvState;
	uint32		RecvSize;

	uint32		sessionId1;
	uint32		sessionId2;

	sint32		State;
}CLIENT_QUEUE;

typedef struct
{
	SOCKET socket;
	uint8 RecvBuffer[512];
	uint32 RecvState;
	uint32 RecvSize;

	uint32 sessionId1;
	uint32 sessionId2;

	/*
	BIGNUM a;
	BIGNUM A;
	BIGNUM B;
	BIGNUM K;
	TABULACRYPT2 tc2;
	*/

	sint32 State;
}CLIENT_GAMELOGIN;

#define MAX_QUEUE_CLIENTS 128
#define MAX_GAMELOGIN_CLIENTS 16

CLIENT_QUEUE Clients_Queue[MAX_QUEUE_CLIENTS];
uint32 ClientsQueueCount = 0;
CLIENT_GAMELOGIN Clients_GameLogin[MAX_GAMELOGIN_CLIENTS];
uint32 ClientsGameLoginCount = 0;

sint32 main()
{
	return 0;
}