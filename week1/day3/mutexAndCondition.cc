/*************************************************************************
 > File Name: MutexLock.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Wed 19 Jun 2019 06:02:57 AM PDT
 ************************************************************************/
#include <func.h>
#include<iostream>
using std::cout;
using std::endl;
#define N 1000000
class MutexLock{
public:
	MutexLock(){
		pthread_mutex_init(&m_mutex,NULL);
	}
	void lock(){
		pthread_mutex_lock(&m_mutex);
	}
	void unlock(){
		pthread_mutex_unlock(&m_mutex);
	}
	~MutexLock(){
		pthread_mutex_destroy(&m_mutex);
	}
private:
	pthread_mutex_t m_mutex;
};
class Condition{
public:
	Condition(){
		pthread_cond_init(&con,NULL);
		pthread_mutex_init(&mutex,NULL);
	}
	void wait(){
		pthread_cond_wait(&con,&mutex);
	}
	void notify(){
		pthread_cond_signal(&con);
	}
	void notifyAll(){
		pthread_cond_broadcast(&con);
	}
private:
	pthread_mutex_t mutex;
	pthread_cond_t con;
};
int n = 0;
void* childFunc(void*p){
	MutexLock * m = (MutexLock*)p;
	cout << m << endl;
	for(int i = 0;i<N;++i){
		m->lock();
		n++;
		m->unlock();
	}
	return NULL;
}
void* childFunc2(void* p){
	Condition * c = (Condition*)p;
	cout << c << endl;
	c->wait();
	printf("wait begin\n");
	sleep(2);
	printf("wait end\n");
	return NULL;
}
int main(int argc,char* argv[]){
	pthread_t id;
	MutexLock mutex;
	Condition c;
	pthread_create(&id,NULL,childFunc2,&c);
	cout << &c << endl;
	c.notify();
	pthread_join(id,NULL);
}

