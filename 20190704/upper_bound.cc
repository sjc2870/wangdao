/*************************************************************************
 > File Name: upper_bound.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Sun 07 Jul 2019 08:20:23 PM PDT
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include <numeric>
#include <vector>
using std::cout;
using std::endl;
int main(int argc,char* argv[]){
	std::vector<int> v{2, 4, 2, 0, 5, 10, 7, 3, 7, 1};
	auto it = std::upper_bound(v.begin(),v.end(),2);
	cout << *it << endl;
}

