/*************************************************************************
 > File Name: consumer.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Mon 15 Jul 2019 07:27:04 AM PDT
 ************************************************************************/

#include "consumer.h"
#include "TaskQueue.h"
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;
namespace wd{
	
void Consumer::run(){
	int num;
	int cnt = 10;
	while(cnt--){
		num = m_taskQueue.pop();
		cout << "Consumer " << pthread_self() << " poped a num " << num << endl;
		sleep(1);
	}
}
}//end of namespace wd
