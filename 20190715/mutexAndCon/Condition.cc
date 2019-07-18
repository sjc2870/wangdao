/*************************************************************************
 > File Name: Condition.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Mon 15 Jul 2019 02:26:53 AM PDT
 ************************************************************************/
#pragma once
#include "Condition.h"
namespace wd{
	Condition::Condition(){
		pthread_cond_init(&m_con,NULL);
		pthread_mutex_init(&m_mutex,NULL);
	}
	void Condition::wait(){
		pthread_cond_wait(&m_con,&m_mutex);
	}
	void Condition::notify(){
		pthread_cond_signal(&m_con);
	}
	void Condition::notifyAll(){
		pthread_cond_broadcast(&m_con);
	}
	Condition::~Condition(){}
}
