#pragma once
#include <pthread.h>
#include <functional>
namespace wd{
class Thread{
public:
	using pthreadCallBack = std::function<void()>;
	Thread(pthreadCallBack &&cb)
	:m_id(0)
	,m_isRunning(false)
	,m_cb(std::move(cb)){	}
	void create();
	void join();
	static void* pthreadFunc(void*);
	~Thread();
private:
	pthread_t m_id;
	bool m_isRunning;
	pthreadCallBack m_cb;
};

}//end of namespace wd
