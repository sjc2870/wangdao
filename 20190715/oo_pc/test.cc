/*************************************************************************
  > File Name: test.cc
  > Author: SJC
  > Mail: 1123305914@qq.com 
  > Created Time: Mon 15 Jul 2019 07:13:09 AM PDT
 ************************************************************************/
#include "TaskQueue.h"
#include "producer.h"
#include "consumer.h"
#include <memory>
#include<iostream>
using std::cout;
using std::endl;
using std::unique_ptr;
using namespace wd;
int main(int argc,char* argv[]){
	TaskQueue taskque = TaskQueue();
	unique_ptr<Thread> producer1(new Producer(taskque));
	unique_ptr<Thread> producer2(new Producer(taskque));
	unique_ptr<Thread> consumer1(new Consumer(taskque));
	unique_ptr<Thread> consumer2(new Consumer(taskque));


	producer1->create();
	producer2->create();
	consumer1->create();
	consumer2->create();


	producer1->join();
	producer2->join();
	consumer1->join();
	consumer2->join();
}

