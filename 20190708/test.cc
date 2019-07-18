/*************************************************************************
 > File Name: test.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Mon 08 Jul 2019 05:20:23 AM PDT
 ************************************************************************/

#include<iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;
int main(int argc,char* argv[]){
	weak_ptr<int>wp;{
		shared_ptr<int> sp(new int(4));
		wp = sp;
		cout << "sp.use_count = " << sp.use_count() << endl;
		cout << "wp.use_count = " << wp.use_count() << endl;
		cout << "wp.expired = " << wp.expired() << endl;
	}
	cout << "wp.expired = " << wp.expired() << endl;
}

