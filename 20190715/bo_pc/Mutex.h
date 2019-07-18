#pragma once

#include <pthread.h>

namespace wd{
class Mutex{
public:
	Mutex();
	void lock();
	void unlock();
	~Mutex();
	pthread_mutex_t* getPtr(){
		return &m_mutex;
	}
private:
	pthread_mutex_t m_mutex;
};

class MutexGuard
:public Mutex{
public:
	MutexGuard(Mutex& mutex)
	:m_mutex(mutex){
		m_mutex.lock();
	}
	~MutexGuard(){
		m_mutex.unlock();
	}
private:
	Mutex &m_mutex;
};
}// end of namespace wd
