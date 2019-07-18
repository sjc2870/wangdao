#pragma once

#include <pthread.h>

namespace wd{
class Mutex{
public:
	Mutex();
	void lock();
	void unlock();
	~Mutex();
private:
	pthread_mutex_t m_mutex;
};
}// end of namespace wd
