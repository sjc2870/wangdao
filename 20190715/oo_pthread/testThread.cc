/*************************************************************************
 > File Name: testThread.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Mon 15 Jul 2019 04:12:03 AM PDT
 ************************************************************************/
#include "Thread.h"
#include<iostream>
#include <memory>
using namespace wd;
using std::unique_ptr;
int main(int argc,char* argv[]){
	unique_ptr<wd::Thread> thread(new MyThread());
	thread->create();
	thread->join();
}

