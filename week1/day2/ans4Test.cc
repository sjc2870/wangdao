/*************************************************************************
  > File Name: ans4Test.cc
  > Author: SJC
  > Mail: 1123305914@qq.com 
  > Created Time: Tue 18 Jun 2019 04:55:11 AM PDT
 ************************************************************************/

#include "ans4.h"
#include <iostream>
using std::cout;
using std::endl;

int main(int argc,char* argv[]){
	String str1;
	str1.print();

	String str2 = "Hello,world";
	String str3("wangdao");

	str2.print();		
	str3.print();	

	String str4 = str3;
	str4.print();

	str4 = str2;
	str4.print();

	return 0;
}

