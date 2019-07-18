/*************************************************************************
 > File Name: Condition.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Mon 15 Jul 2019 02:26:53 AM PDT
 ************************************************************************/
#include "Mutex.h"
#include "Condition.h"
#include <iostream>
namespace wd{
	Condition::Condition(Mutex& mutex)
	:m_mutex(mutex){
		pthread_cond_init(&m_con,NULL);
	}
	void Condition::wait(){
		if(pthread_cond_wait(&m_con,m_mutex.getPtr())){
			perror("pthread_wait");
		}
	}
	void Condition::notify(){
		pthread_cond_signal(&m_con);
	}
	void Condition::notifyAll(){
		pthread_cond_broadcast(&m_con);
	}
	Condition::~Condition(){}
}
