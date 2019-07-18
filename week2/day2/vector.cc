/*************************************************************************
 > File Name: vector.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Wed 26 Jun 2019 12:23:02 AM PDT
 ************************************************************************/
#include <vector>
#include<iostream>
using std::cout;
using std::endl;
using std::vector;
using std::cin;
int main(int argc,char* argv[]){
	vector<char> v;
	char c;
	while((c = cin.get())!='\n'){
		v.push_back(c);
	}
	cout << v.data() << endl;
}

