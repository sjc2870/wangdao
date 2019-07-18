#pragma once
#include "Mutex.h"
#include "Task.h"
#include "Condition.h"
#include <queue>
using namespace wd;
typedef Task* ELETYPE;
using std::queue;
namespace wd{
class TaskQueue{
public:
	TaskQueue(size_t size = 10);
	void push(ELETYPE);
	ELETYPE pop();
	bool empty();
	bool full();
	void wakeup();
private:
	size_t m_queSize;
	queue<ELETYPE> m_que;
	Mutex m_mutex;
	Condition m_notEmpty;
	Condition m_notFull;
	bool m_flag;
};
}
