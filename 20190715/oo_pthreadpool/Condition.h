#pragma once

#include <pthread.h>

namespace wd{
class Mutex;
class Condition{
public:
	Condition(Mutex&);
	void wait();
	void notify();
	void notifyAll();
	~Condition();
private:
	Mutex& m_mutex;
	pthread_cond_t m_con;
};
}//end of namespace wd
