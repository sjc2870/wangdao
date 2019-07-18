/*************************************************************************
 > File Name: wordLadder.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Mon 08 Jul 2019 05:42:49 AM PDT
 ************************************************************************/

#include<iostream>
#include <string>
#include <set>
#include <queue>
#include <stack>
using std::stack;
using std::set;
using std::cout;
using std::endl;
using std::string;
using std::queue;
class Solution{
public:
	Solution(string beg,string end)
	:m_begin(beg)
	,m_end(end){
		
	}
	int ladderLength(const set<string>& wordList);
private:
	stack<string> getNext(string s,const set<string>& wordList){
		stack<string> ret;
		for(auto &ss:wordList){
			int diff = 0;
			for(int i = 0;i<s.size();++i){
				if(ss[i]!=s[i]){
					++diff;
				}
			}
			if(diff==1){
				ret.push(ss);
			}
		}
		return ret;
	}
private:
	string m_begin;
	string m_end;
};
int Solution::ladderLength(const set<string>& wordList){
	int len = 1;
	set<string> visited;
	queue<string> curr_que;
	queue<string> next_que;
	curr_que.push(m_begin);
	while(1){
		string s1 = curr_que.front();
		stack<string> ret = getNext(s1,wordList);
		while(!ret.empty()){
			string s2 = ret.top();
			ret.pop();
			if(visited.find(s2)==visited.end()){
				//如果这个单词还没使用过
				//cout << s2 ;
				if(s2==m_end){
					goto end;
				}
				visited.insert(s2);
				next_que.push(s2);
			}
		}
		//cout << endl;
		curr_que.pop();
		if(curr_que.empty()){
			curr_que = next_que;
			while(!next_que.empty()){
				next_que.pop();
			}
		}
		len++;
	}
end:
	return len;
}
int main(int argc,char* argv[]){
	Solution s("hit","cog");
	set<string> sset{"hot","dot","dog","lot","log","cog"};
	int len = s.ladderLength(sset);
	cout << "len = " << len << endl;
}

