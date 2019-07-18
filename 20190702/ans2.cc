/*************************************************************************
 > File Name: ans2.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Tue 02 Jul 2019 05:38:44 AM PDT
 ************************************************************************/
#include<iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
using std::cout;
using std::vector;
using std::endl;
using std::cin;
using std::string;
using std::map;
using std::set;
class TextQuery{
public:
	TextQuery(const string &fileName,const string& word)
	:m_fileName(fileName)
	,m_queriedWord(word){
		
	}
	void readFile();
	void query() ;
	void print(){
		auto it = m_lines.begin();
		while(it!=m_lines.end()){
			cout << it->first << ":" << it->second << endl;
			++it;
		}
	}
private:
	string m_fileName;
	string m_queriedWord;
	map<int,string> m_lines; //存储文件行号和行内容
};
void TextQuery::readFile() {
	std::ifstream ifs(m_fileName);
	char line[1024] = {0};
	int num = 1;
	//存储文件内容到map<int string> lines中
	while(ifs.good()){
		ifs.getline(line,1024,'\n');
		m_lines.insert(std::make_pair(num,line));
		num++;
	}
}

void TextQuery::query() {
	int wordCnt = 0;
	string word;
	auto it = m_lines.begin();
	set<int> match;
	while(it!=m_lines.end()){
		std::istringstream iss(it->second);
		while(iss.good()){
			iss >> word;
			string subs = word.substr(0,word.size()-2);
			char punct = word[word.size()-1];
			//如果单词相等 或者除单词最后一个符号外相等
			if((word.compare(m_queriedWord)==0) || \
					(subs.compare(m_queriedWord)==0&&ispunct(punct))){
				++wordCnt;
				match.insert(it->first);
			}
		}
		++it;
	}

	//打印
	cout << m_queriedWord << " occurs " << wordCnt << " times " << endl << endl;;
	auto it2 = match.begin();
	while(it2!=match.end()){
		cout << "(line" << *it2 << ") ";
		cout << m_lines[*it2] << endl;
		++it2;
	}
}
int main(int argc,char* argv[]){
	//读取文件名和想要查询的单词
	string word;
	string fileName;
	std::ifstream ifs;
	cout << "请输入文件名：" << endl;
	cin >> fileName;
	ifs.open(fileName);
	while(!ifs.good()){
		cout << "请重新输入文件名"  << endl;
		cin >> fileName;
		ifs.open(fileName);
	}
	cout << "请输入想要查询的单词" << endl;
	cin >> word;
	//读入文件名和想要查询的单词完毕
	TextQuery tq(fileName,word);
	tq.readFile();
	//tq.print();
	tq.query();
}

