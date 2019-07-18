/*************************************************************************
 > File Name: single.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Tue 25 Jun 2019 01:46:37 AM PDT
 ************************************************************************/

#include<iostream>
using std::cout;
using std::endl;
class Single{
public:
	static Single *getInstance(){
		if(m_pstr==NULL){
			m_pstr = new Single();
		}
		return m_pstr;
	}
	static void destory(){
		if(m_pstr){
			delete m_pstr;
		}
	}
private:
	Single(){cout << "Single()" << endl;}
	~Single() {cout << "~Single()" << endl;}
	static Single* m_pstr;
	int data;
};
Single* Single::m_pstr = NULL;
int main(int argc,char* argv[]){
	Single *s = Single::getInstance();
	cout << sizeof(*s) << endl;
}

