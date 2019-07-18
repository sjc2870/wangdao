/*************************************************************************
 > File Name: taskQueue.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Mon 15 Jul 2019 06:27:36 AM PDT
 ************************************************************************/
#include "TaskQueue.h"
#include<iostream>
#include <queue>
using std::queue;
using std::cout;
using std::endl;

namespace wd{
	TaskQueue::TaskQueue(size_t size)
	:m_queSize(size)
	,m_mutex()
	,m_notEmpty(m_mutex)
	,m_notFull(m_mutex){

	}
	
	bool TaskQueue::empty(){
		return m_que.size()==0;
	}
	bool TaskQueue::full(){
		return m_que.size()==m_queSize;
	}

	void TaskQueue::push(ELETYPE value){
		MutexGuard mg = MutexGuard(m_mutex);
		while(full()){
			m_notFull.wait();
		}
		m_que.push(value);
		m_notEmpty.notify();
	}

	ELETYPE TaskQueue::pop(){
		MutexGuard mg = MutexGuard(m_mutex);
		while(empty()){
			m_notEmpty.wait();
		}
		ELETYPE num = m_que.front();
		m_que.pop();

		m_notFull.notify();
		return num;
	}
}//end of namespace wd
