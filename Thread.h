#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include <windows.h>
#define Thread_ID DWORD 
#define THREADRET DWORD 
#define THREAD_ROUTINE LPTHREAD_START_ROUTINE
#define THREAD_ROUTINE2 LPTHREAD_START_ROUTINE function
#define TMutex CRITICAL_SECTION


namespace Thread
{
	void initMutex( TMutex* mutex ) noexcept;
	void destroyMutex( TMutex* mutex ) noexcept;
	void lockMutex( TMutex* Mutex ) noexcept;
	void unlockMutex( TMutex* Mutex ) noexcept;

	bool New( Thread_ID* id, THREAD_ROUTINE2, void* parameter) noexcept;
	bool Cancel( Thread_ID id ) noexcept;
	void Join( Thread_ID id ) noexcept;
	void Exit( void) noexcept;
}