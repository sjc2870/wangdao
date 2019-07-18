/*************************************************************************
 > File Name: test.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Wed 03 Jul 2019 01:16:17 AM PDT
 ************************************************************************/

#include<iostream>
#include <iterator>
#include <algorithm>
#include <sstream>
using std::cout;
using std::endl;

int main(int argc,char* argv[]){
#if 0
	std::istringstream stream("1 2 3 4 5");
	std::copy(std::istream_iterator<int>(stream),std::istream_iterator<int>(),
			std::ostream_iterator<int>(std::cout,","));
#endif
	std::ostream_iterator<int> osi(std::cout,",");
	*osi = 2;
}

