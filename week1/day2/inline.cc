/*************************************************************************
 > File Name: inline.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Tue 18 Jun 2019 05:40:11 AM PDT
 ************************************************************************/

#include<iostream>
using std::cout;
using std::endl;

#define MULTY(a,b) a*b
inline int multy(int a,int b){
	return a*b;
}
int main(int argc,char* argv[]){
	int a = 3,b = 4,c = 5;
	cout << MULTY(a+b,c) << endl;
	cout << multy(a+b,c) << endl;
}

