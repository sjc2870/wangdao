/*************************************************************************
 > File Name: Thread.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Mon 15 Jul 2019 05:30:25 AM PDT
 ************************************************************************/
#include "Thread.h"
namespace wd{

void Thread::create(){
	pthread_create(&m_id,nullptr,pthreadFunc,this);
	m_isRunning = true;
}

void* Thread::pthreadFunc(void *arg){
	Thread* thread = static_cast<Thread*> (arg);
	thread->m_cb();
	return nullptr;
}
void Thread::join(){
	if(m_isRunning){
		pthread_join(m_id,nullptr);
	}
}
Thread::~Thread(){
	if(m_isRunning){
		pthread_detach(m_id);
	}
}
}//end of namespace wd
