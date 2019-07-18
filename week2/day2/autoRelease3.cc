/*************************************************************************
 > File Name: autoRelease3.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Wed 26 Jun 2019 02:09:27 AM PDT
 ************************************************************************/
#include <pthread.h>
#include<iostream>
using std::cout;
using std::endl;
class Single{
public:
	static Single* getInstance(){
		pthread_once(&m_once,init);
		return m_pInstance;
	}
	static void init(){
		m_pInstance  = new Single();
		atexit(destory);
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
	static pthread_once_t m_once;
};
Single* Single::m_pInstance = nullptr;
pthread_once_t Single::m_once = PTHREAD_ONCE_INIT;
int main(int argc,char* argv[]){
	Single *p = Single::getInstance();

}

