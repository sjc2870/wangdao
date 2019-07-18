/*************************************************************************
 > File Name: all_of.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Sun 07 Jul 2019 07:35:16 PM PDT
 ************************************************************************/

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;

int main(int argc,char* argv[]){
	vector<int> vec(10,2);
	partial_sum(vec.cbegin(),vec.cend(),vec.begin());
	cout << "Among the vector:\n";
	copy(vec.begin(),vec.end(),std::ostream_iterator<int>(cout," "));
	auto ret = all_of(vec.begin(),vec.end(),[](int n) -> bool {return n%2 ==0;});
	if(ret){
		cout << endl << "all is even" << endl;
	}
	ret = none_of(vec.begin(),vec.end(),std::bind(std::modulus<int>(),std::placeholders::_1,2));
	if(ret){
		cout << "none of them are odd" << endl;
	}
	struct DivisibleBy{
		const int d;
		DivisibleBy(int n):d(n){}
		bool operator()(int n) const {return n%d==0;}
	};
	ret = any_of(vec.begin(),vec.end(),DivisibleBy(7));
	if(ret){
		cout << "at least one number is divisible by 7" << endl;
	}
}

