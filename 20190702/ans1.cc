/*************************************************************************
 > File Name: ans1.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Tue 02 Jul 2019 01:53:45 AM PDT
 ************************************************************************/

#include<iostream>
#include <map>
#include <string>
#include <fstream>
using std::cout;
using std::endl;
using std::map;
using std::ifstream;
using std::string;

int main(int argc,char* argv[]){
	map<string,int,std::greater<string>> m;
	ifstream ifs("bible_handle.txt");
	char s[100] = {0};
	while(ifs.good()){
		ifs >> s;
		//cout << s << endl;
		auto it = m.find(s);
		if(it==m.end()){
			m.insert(std::make_pair(s,1));
		}else{
			++it->second;
		}
	}
	auto it = m.begin();
	map <int,string,std::greater<int>> m2;
	while(it!=m.end()){
		m2.insert(make_pair(it->second,it->first));
		++it;
	}
	auto it2 = m2.begin();
#if 1
	int i = 0;
	while(i<10){
		cout << it2->second << "-->" << it2->first << endl;
		++it2;
		++i;
	}
#endif

}

