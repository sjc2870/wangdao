/*************************************************************************
 > File Name: ans1.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Wed 26 Jun 2019 01:26:38 AM PDT
 ************************************************************************/

#include<iostream>
using std::cout;
using std::endl;

class Single{
	class autoRelease{
		public:
		autoRelease(){ cout << "autoRelease()" << endl;}
		~autoRelease() {
			Single::destory();
			cout << "~autoRelease" << endl;
		}
	};
public:
	static Single* getInstance(){
		if(m_pInstance==nullptr){
			m_pInstance = new Single();
		}
		return m_pInstance;
	}

	static void destory(){
		if(m_pInstance){
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}
private:
	Single(){cout << "Single()" << endl; }
	~Single() {cout << "~Single()" << endl; }
private:
	static Single* m_pInstance;
	static autoRelease autorelease;
};
Single* Single::m_pInstance = getInstance();
Single::autoRelease Single::autorelease {};
int main(int argc,char* argv[]){
	Single *p = Single::getInstance();
}

