/*************************************************************************
 > File Name: bind.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Mon 08 Jul 2019 12:16:05 AM PDT
 ************************************************************************/

#include<iostream>
#include <functional>
using std::cout;
using std::endl;
using namespace std::placeholders;
void f(int a,int b,int c){
	cout << a << " "
		 << b << " "
		 << c << endl;
}
struct Test{
	Test(int n=0)
	:m_data(n){
		
	}
	void print(){
		cout << m_data << endl;
	}
	int m_data;
};
int main(int argc,char* argv[]){
	auto f1 = std::bind(f,_2,_1,10);
	f1(1,2);
	Test t(10);
	auto f2 = std::bind(&Test::print,&t);
	f2();
	Test t1(11);
	auto f3 = std::bind(&Test::m_data,_1);
	cout << f3(&t1) << endl;;
}

