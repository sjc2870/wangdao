#pragma once
#include <pthread.h>

namespace wd{
class Thread{
public:
	Thread(pthread_t id=0)
	:m_id(id)
	,m_isRunning(false)		{	}
	void create();
	void join();
	static void* pthreadFunc(void*);
	~Thread();
private:
	virtual void run() = 0;
private:
	pthread_t m_id;
	bool m_isRunning;
};

class MyThread
:public Thread{
public:
	void run();
};
}
