/*************************************************************************
 > File Name: HelloWorld.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Mon 01 Jul 2019 07:24:07 AM PDT
 ************************************************************************/

#include<iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
using std::cout;
using std::endl;

int main(int argc,char* argv[]){
	log4cpp::OstreamAppender* osAppender  = new log4cpp::OstreamAppender("osAppender",&cout);
	osAppender->setLayout(new log4cpp::BasicLayout);

	log4cpp::Category&root = log4cpp::Category::getRoot();
	root.addAppender(osAppender);
	root.setPriority(log4cpp::Priority::DEBUG);

	root.error("Hello logcpp in a Error Message!");
	root.warn("Hello logcpp in a Warning Message!");
	log4cpp::Category::shutdown();
	return 0;
}

