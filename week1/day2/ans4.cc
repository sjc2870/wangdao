/*************************************************************************
  > File Name: ans4.cc
  > Author: SJC
  > Mail: 1123305914@qq.com 
  > Created Time: Tue 18 Jun 2019 04:44:26 AM PDT
 ************************************************************************/
#include "ans4.h"
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

String::String()   //默认构造函数
	:m_pstr(NULL)
{
}

String::String(const char* pstr)//构造函数
	:m_pstr(new char [strlen(pstr)+1]())
{
	strcpy(m_pstr,pstr);
	cout << "This is create func" << endl;
}

String::String(const String&rhs)//复制构造函数
	:m_pstr(new char [strlen(rhs.m_pstr)+1]())
{
	strcpy(m_pstr,rhs.m_pstr);
	cout << "This is copy create func" << endl;
}

String::~String(){
	if(m_pstr!=NULL){
		delete []m_pstr;
	}
	cout << "This is destruct func" << endl;
}

void String::print(){
	if(m_pstr!=NULL){
		cout << "string = "<< m_pstr << endl;
	}
}
