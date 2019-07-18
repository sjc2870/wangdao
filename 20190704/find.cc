/*************************************************************************
 > File Name: find.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Sun 07 Jul 2019 06:33:08 PM PDT
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
struct Sum{
	Sum()
	:m_sum(0){ }
	void operator()(int n){
		m_sum +=n;
	}
	int m_sum;
};
int main(int argc,char* argv[]){
	vector<int> ivc{1,3,5,7,9};
	auto print = [](const int&n){
		cout << n << " ";
	};
	cout << "before:" << endl;
	for_each(ivc.begin(),ivc.end(),print);
	for_each(ivc.begin(),ivc.end(),[](int &n){ n++;});
	cout << endl;
	cout << "end:" << endl;
	for_each(ivc.begin(),ivc.end(),print);
	cout << endl;
}

