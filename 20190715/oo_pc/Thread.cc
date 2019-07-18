/*************************************************************************
 > File Name: Thread.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Mon 15 Jul 2019 02:48:55 AM PDT
 ************************************************************************/

#include "Thread.h"
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;
namespace wd{
	void Thread::create(){
		pthread_create(&m_id,nullptr,pthreadFunc,this);
		m_isRunning = true;
	}
	void Thread::join(){
		if(m_isRunning){
			pthread_join(m_id,nullptr);
		}
	}
	void* Thread::pthreadFunc(void* arg){
		Thread* thread = (Thread*)arg;
		thread->run();
		return nullptr;
	}
	void MyThread::run(){
		int cnt = 10;
		::srand(time(nullptr));
		int num;
		while(cnt--){
			num = rand() % 100;
			cout << "childPthread " << pthread_self() << ",num = " << num << endl;
			sleep(1);
		}
	}
	Thread::~Thread(){
		if(m_isRunning){
			pthread_detach(m_id);
		}
	}
}//end of namespace wd

