#pragma once
#include "Thread.h"
#include "TaskQueue.h"
#include <vector>
#include <memory>
using std::unique_ptr;
using std::vector;

namespace wd{

class ThreadPool{
public:
	ThreadPool(size_t threadNum = 2,size_t queSize = 10)
	:m_threadNum(threadNum)
	,m_queSize(queSize)
	,m_taskQueue(queSize)
	,m_isExit(false){
		m_threads.reserve(threadNum);
	}
	void start();
	void stop();
	void addTask(ELETYPE);
	ELETYPE getTask();
	void threadFunc();
	
private:
	size_t m_threadNum;
	size_t m_queSize;
	vector<unique_ptr<Thread>>  m_threads;
	TaskQueue m_taskQueue;
	bool m_isExit;
};
}//end of namespace wd
