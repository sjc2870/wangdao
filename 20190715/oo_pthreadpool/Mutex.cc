/*************************************************************************
 > File Name: MutexLock.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Wed 19 Jun 2019 06:02:57 AM PDT
 ************************************************************************/
#include "Mutex.h"
#include <func.h>
#include<iostream>
using std::cout;
using std::endl;
#define N 1000000
namespace wd{
	Mutex::Mutex(){
		pthread_mutex_init(&m_mutex,NULL);
	}
	void Mutex::lock(){
		pthread_mutex_lock(&m_mutex);
	}
	void Mutex::unlock(){
		pthread_mutex_unlock(&m_mutex);
	}
	Mutex::~Mutex(){
		pthread_mutex_destroy(&m_mutex);
	}
}
