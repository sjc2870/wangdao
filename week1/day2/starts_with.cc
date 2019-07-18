/*************************************************************************
 > File Name: starts_with.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Tue 18 Jun 2019 07:28:51 AM PDT
 ************************************************************************/

#include<iostream>
#include <string>
using std::cout;
using std::endl;

int main(int argc,char* argv[]){
	std::string s ("helloworld");
	std::string s1("haha");
	//s.starts_with("hello");
	//s.insert(5,"haha",2);
	s.insert(5,s1);
	cout << s << endl;
}

