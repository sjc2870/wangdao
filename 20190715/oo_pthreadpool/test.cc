/*************************************************************************
 > File Name: test.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Tue 16 Jul 2019 06:11:25 AM PDT
 ************************************************************************/
#include "ThreadPool.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include<iostream>
using std::cout;
using std::endl;

namespace wd{

class MyTask
:public Task{
public:
	void start(){
		int num;
		srand(time(nullptr));
		num = rand()%100;
		cout << "childThread " << pthread_self() 
			 << " MyTask,num = " << num << endl;
		sleep(1);
	}
	~MyTask(){
	}
};
}// end of namespace wd
int main(int argc,char* argv[]){
	unique_ptr<Task> task(new MyTask());
	ThreadPool threadpool;
	threadpool.start();
	
	int cnt = 10;
	while(cnt--){
		threadpool.addTask(task.get());
	}

	threadpool.stop();
}

