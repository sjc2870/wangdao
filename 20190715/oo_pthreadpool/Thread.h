#pragma once
#include <pthread.h>

namespace wd{
class ThreadPool;
class Thread{
public:
	Thread(pthread_t id=0)
	:m_id(id)
	,m_isRunning(false)		{	}
	void create();
	void join();
	static void* pthreadFunc(void*);
	virtual ~Thread();
private:
	virtual void run() = 0;
private:
	pthread_t m_id;
	bool m_isRunning;
};

class WorkThread
:public Thread{
public:
	WorkThread(ThreadPool& threadpool)
	:m_threadpool(threadpool){
		
	}
	void run();
private:
	ThreadPool & m_threadpool;
};
}
