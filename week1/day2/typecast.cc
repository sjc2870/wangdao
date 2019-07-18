/*************************************************************************
 > File Name: typecast.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Tue 18 Jun 2019 05:18:44 AM PDT
 ************************************************************************/
#include <stdlib.h>
#include <string.h>
#include<iostream>
using std::cout;
using std::endl;

int main(int argc,char* argv[]){
	double d = 1.11;
	int i = static_cast<int>(d);
	int *k = static_cast<int*>(calloc(1,sizeof(int)));
	cout << i << endl;
	cout << *k << endl;
	free(k);
}

