/*************************************************************************
 > File Name: test.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Mon 15 Jul 2019 08:41:08 AM PDT
 ************************************************************************/
#include "TaskQueue.h"
#include "Mutex.h"
#include "Condition.h"
#include "Thread.h"
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include<iostream>
#include <memory>
using std::unique_ptr;
using std::cout;
using std::endl;
using namespace wd;
class Producer{
public:
	void func(TaskQueue& tq){
		int cnt = 10;
		int num;
		srand(time(nullptr));
		while(cnt--){
			num = rand()%100;
			tq.push(num);
			cout << "producer " << pthread_self() << ",pushed a num " << num << endl;
		}
	}
};
class Consumer{
public:
	void func(TaskQueue &tq){
		int cnt = 10;
		int num;
		while(cnt--){
			num = tq.pop();
			cout << "Consumer " << pthread_self() << ",num = " << num << endl;
			sleep(1);
		}
	}
};
int main(int argc,char* argv[]){
		TaskQueue tq(10);
	unique_ptr<Thread> producer1 (new Thread(
				std::bind(&Producer::func,Producer(),std::ref(tq))
				));
	unique_ptr<Thread> consumer1 (new Thread(
				std::bind(&Consumer::func,Consumer(),std::ref(tq))
				));
	producer1->create();
	consumer1->create();

	producer1->join();
	consumer1->join();
}

