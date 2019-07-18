#pragma once
#include <pthread.h>
#include <functional>
using std::function;
namespace wd{
class Thread{
public:
	using ThreadCallBack = function<void()>;
	Thread(ThreadCallBack &&cb)
	:m_id(0)
	,m_isRunning(false)
	,m_cb(std::move(cb))	{	}
	
	void create();
	void join();
	static void* pthreadFunc(void*);
	~Thread();
private:
	pthread_t m_id;
	bool m_isRunning;
	ThreadCallBack m_cb;
};
}//end of namespace wd
