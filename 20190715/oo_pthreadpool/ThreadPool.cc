/*************************************************************************
 > File Name: ThreadPool.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Tue 16 Jul 2019 05:21:27 AM PDT
 ************************************************************************/

#include "ThreadPool.h"
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;
namespace wd{

void ThreadPool::start(){
	for(int i = 0;i<m_threadNum;++i){
		unique_ptr<Thread> pthread(new WorkThread(*this));
		m_threads.push_back(std::move(pthread));
	}
	for(auto & pthread:m_threads){
		pthread->create();
	}
}
void ThreadPool::stop(){
	if(!m_isExit){
		while(!m_taskQueue.empty()){
			sleep(1);
		}

		m_isExit = true;
		m_taskQueue.wakeup();
		for(auto &thread:m_threads){
			thread->join();
		}
	}
}

void ThreadPool::addTask(ELETYPE task){
	if(!m_isExit){
		m_taskQueue.push(task);
	}
}

ELETYPE ThreadPool::getTask(){
		return m_taskQueue.pop();
}

void ThreadPool::threadFunc(){
	//if(!m_isExit){
	while(!m_isExit){
		ELETYPE task = getTask();
		if(task){
			task->start();
		}
	}
}
}// end of namespace wd
