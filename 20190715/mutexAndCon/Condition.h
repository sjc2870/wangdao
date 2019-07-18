#pragma once

#include <pthread.h>

namespace wd{
class Condition{
public:
	Condition();
	void wait();
	void notify();
	void notifyAll();
	~Condition();
private:
	pthread_mutex_t m_mutex;
	pthread_cond_t m_con;
};
}//end of namespace wd
