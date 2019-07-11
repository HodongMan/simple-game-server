#include "Thread.h"

void Thread::initMutex( TMutex* Mutex ) noexcept 
{ 
	InitializeCriticalSection( Mutex ); 
}

void Thread::destroyMutex( TMutex* Mutex ) noexcept 
{ 
	DeleteCriticalSection( Mutex ); 
}

void Thread::lockMutex( TMutex* Mutex ) noexcept
{ 
	EnterCriticalSection( Mutex ); 
}

void Thread::unlockMutex( TMutex* Mutex ) noexcept
{ 
	LeaveCriticalSection( Mutex ); 
}

bool Thread::New( Thread_ID* id, THREAD_ROUTINE2, void* parameter ) noexcept
{
	HANDLE handle = CreateThread( nullptr, 0, (LPTHREAD_START_ROUTINE)function, parameter, 0, id );
	if ( nullptr == handle ) 
	{ 
		return false; 
	}

	return true;
}

bool Thread::Cancel( Thread_ID id ) noexcept
{
	HANDLE handle = OpenThread( THREAD_TERMINATE, false, id );
	if ( 0 == TerminateThread( handle, 0 ) ) 
	{ 
		return false; 
	}

	return true;
}

void Thread::Join( Thread_ID id ) noexcept
{
	HANDLE handle = OpenThread( THREAD_ALL_ACCESS, false, id );
	
	WaitForSingleObject( handle, INFINITE );
}

void Thread::Exit( void ) noexcept
{
	ExitThread( 0 );
}