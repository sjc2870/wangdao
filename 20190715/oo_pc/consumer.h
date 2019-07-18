#pragma once
#include "Thread.h"

namespace wd{
class TaskQueue;
class Consumer
:public Thread{
public:
	Consumer(TaskQueue& taskQueue)
	:m_taskQueue(taskQueue){
		
	}
	void run();
private:
	TaskQueue &m_taskQueue;
};
}//end of namespace wd
