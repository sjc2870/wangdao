/*************************************************************************
 > File Name: autoRelease2.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Wed 26 Jun 2019 01:47:58 AM PDT
 ************************************************************************/
#include <stdlib.h>
#include<iostream>
using std::cout;
using std::endl;
//atexit()
class Single{
public:
	static Single *getInstance(){
		if(m_pInstance==nullptr){
			m_pInstance = new Single();
			atexit(destory);
		}
		return m_pInstance;
	}
	static void destory(){
		if(m_pInstance){
			delete m_pInstance;
		}
	}
private:
	Single(){cout << "Single()" << endl;}
	~Single(){cout << "~Single()" << endl;}
private:
	static Single* m_pInstance;
};
Single* Single:: m_pInstance = getInstance();
int main(int argc,char* argv[]){
	Single *p = Single::getInstance();
	
}

