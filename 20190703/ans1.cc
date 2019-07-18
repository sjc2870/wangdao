/*************************************************************************
 > File Name: ans1.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Wed 03 Jul 2019 01:25:56 AM PDT
 ************************************************************************/

#include <string.h>
#include<iostream>
#include <stack>
#include <sstream>
using std::string;
using std::stack;
using std::cout;
using std::endl;
using std::cin;

int main(int argc,char* argv[]){
	char s[1024] = {0};
	int i;
	char c;
	while(cin.good()){
		stack<char> stk;
beg:
		cout << "请输入有效数据"  << endl;
		i = 0;
		cin.getline(s,1024,'\n');
		for(i=0;i<strlen(s);++i){
			c = s[i];
			switch(c){
				case '(':
					if(i==strlen(s)-1){
						cout << "false" << endl;
						goto beg;
					}else{
						stk.push(c);
					}
					break;
				case '{':
					if(i==strlen(s)-1){
						cout << "false" << endl;
						goto beg;
					}else{
						stk.push(c);
					}
					break;
				case '[':
					if(i==strlen(s)-1){
						cout << "false" << endl;
						goto beg;
					}else{
						stk.push(c);
					}
					break;
				case ')':
					if(stk.top()!='('){
						cout << "false" << endl;
						goto beg;
					}else{
						stk.pop();
					}
					break;
				case '}':
					if(stk.top()!='{'){
						cout << "false" << endl;
						goto beg;
					}else{
						stk.pop();
					}
					break;
				case ']':
					if(stk.top()!='['){
						cout << "false" << endl;
						goto beg;
					}else{
						stk.pop();
					}
					break;
				default:
					cout << "输入有误," ;
					goto beg;
			}
		}
		cout << "true" << endl;
	}
}

