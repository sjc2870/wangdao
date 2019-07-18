/*************************************************************************
  > File Name: wordLadder.cc
  > Author: SJC
  > Mail: 1123305914@qq.com 
  > Created Time: Wed 03 Jul 2019 01:58:21 AM PDT
 ************************************************************************/

#include<iostream>
#include <string>
#include <set>
#include <stack>
#include <vector>
using std::stack;
using std::cout;
using std::endl;
using std::string;
using std::set;
using std::vector;
using std::cin;
class Solution{
	public:
		int ladderLength(string beginWord,
				string endWord,
				set <string>& wordList);
};
class Data{
	//需要回朔的数据   set<string> cnt
	public:
		Data(set<string> wordList,int step)
			:m_wordList(wordList.begin(),wordList.end())
			 ,m_step(step){

			 }
		//数据也是public的
		set<string> m_wordList;
		int m_step;
};
int Solution::ladderLength(string beginWord,string endWord,set<string>& wordList){
	int step=0;
	int diff = 0;
	set<int> len;//多个len，选取其中最小的那个
	string last = beginWord;
	stack<Data> stk;
	int flag = 0;
	if(!wordList.count(endWord)){
		return 0;
	}
	stk.push(Data(wordList,step));
	int j=0,k=0;
beg:
	while(!stk.empty()){
		//更新wordList和step等变量
		j++;
		cout << "第" << j << "次外循环" << endl;
		wordList = stk.top().m_wordList;
		int diffWordNum = 0;
		step = stk.top().m_step;
		stk.pop();
		string saveWord = beginWord;
		vector<string> eraseWord;
		int endflag=0;
		while(1){
			k++;
			cout << "第" << k << "次内循环" << endl;
			//选出和最后一个单词只差一个字母的单词数量
			for(auto &s:wordList){
				diff=0;
				for(int i = 0;i<beginWord.size();++i){
					if(last[i]!=s[i]){
						++diff;
					}
				}
				if(diff==1){
					if(flag==1){
						eraseWord.push_back(s);
					}else{
						flag=1;
						last = s;
						auto it = wordList.find(last);
						if(it!=wordList.end()){
							wordList.erase(it);
						}
						//如果单词梯的最后一个单词正好是尾单词，那么本次查找结束
						if(s==endWord){
							len.insert(step);
							endflag=1;//代表查找到了最后的单词，压栈后结束本次查找
						}
					}
					++diffWordNum;
				}
			}
			++step;
			//如果符合条件的单词数量大于1，把数据压栈，方便回朔
			if(diffWordNum>1){
				//将去除保留单词的set压栈
				stk.push(Data(wordList,step));
				auto it = wordList.find(last);
				if(it!=wordList.end()){
					stk.top().m_wordList.erase(it);
				}
			}
			if(endflag==1){
				goto beg;
			}
			//把多余分支去除掉
			for(auto &s:eraseWord){
				auto it = wordList.find(s);
				wordList.erase(it);
			}
		}
	}
	auto it = len.begin();
	return *it;
}
int main(int argc,char* argv[]){
	Solution slu;
	string beginWord,endWord,s;
	set<string> wordList;
	cin >> beginWord >> endWord;
	while(cin.good()){
		cin >> s;
		wordList.insert(s);
	}
	int ret =slu.ladderLength(beginWord,endWord,wordList);
	cout << ret << endl;
}

