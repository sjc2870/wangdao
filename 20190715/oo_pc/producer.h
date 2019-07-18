#include "Thread.h"
namespace wd{
class TaskQueue;
class Producer
:public Thread{
public:
	Producer(TaskQueue& taskQueue)
	:m_taskQueue(taskQueue){}
	void run();
private:
	TaskQueue &m_taskQueue;
};
}//end of namespace wd
