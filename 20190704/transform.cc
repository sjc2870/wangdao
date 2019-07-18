/*************************************************************************
 > File Name: transform.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Sun 07 Jul 2019 07:08:21 PM PDT
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main(int argc,char* argv[]){
	vector<int> ivec1 = {1,3,5,7,9};
	vector<int> ivec2;
	ivec2.reserve(5);
	transform(ivec1.begin(),ivec1.end(),std::back_inserter(ivec2),
			[](int n) ->int {return ++n;});
	auto print = [](const int&n){cout << n << " ";};
	for_each(ivec1.begin(),ivec1.end(),print);
	cout << endl;
	for_each(ivec2.begin(),ivec2.end(),print);
	cout << endl;
}

