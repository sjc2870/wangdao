/*************************************************************************
 > File Name: testThread.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Mon 15 Jul 2019 05:38:30 AM PDT
 ************************************************************************/


#include "Thread.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <iostream>
#include <memory>
using namespace wd;
using std::cout;
using std::endl;
using std::unique_ptr;
class MyTask{
public:
void func(){
	int cnt = 10;
	srand(time(nullptr));
	int num;
	while(cnt--){
		num = rand()%100;
		cout << "childPthread " << pthread_self() << ",num = " << num << endl;
	}
}
};
int main(int argc,char* argv[]){
	unique_ptr<Thread> thread(new Thread(
				std::bind(&MyTask::func,MyTask())
				));
	thread->create();
	thread->join();
}

