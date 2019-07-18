/*************************************************************************
 > File Name: default.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Tue 18 Jun 2019 05:43:44 AM PDT
 ************************************************************************/

#include<iostream>
using std::cout;
using std::endl;

int add(int a,int b=0){
	return a+b;
}

int main(int argc,char* argv[]){
	int a=3,b=4;
	cout << add(a,b) << endl;
	cout << add(a) << endl;
}

