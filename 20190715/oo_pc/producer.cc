/*************************************************************************
 > File Name: producer.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Mon 15 Jul 2019 06:15:50 AM PDT
 ************************************************************************/
#include "producer.h"
#include "TaskQueue.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include<iostream>
using std::cout;
using std::endl;

namespace wd{

void Producer::run(){
	int cnt = 10;
	::srand(time(nullptr));
	int num;
	while(cnt--){
		num = rand()%100;
		m_taskQueue.push(num);
		cout << "producer " << pthread_self() << ",pushed a num " << num << endl;
	}
}
}
