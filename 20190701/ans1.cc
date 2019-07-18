/*************************************************************************
 > File Name: ans1.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Mon 01 Jul 2019 05:18:32 AM PDT
 ************************************************************************/

#include<iostream>
using std::cout;
using std::endl;
using std::ostream;
template <class T>
class Queue{
public:
	Queue(int size = 10)
	:m_data(new T[size]())
	,m_rear(0)
	,m_head(0)
	,m_size(size){
		cout << "Queue(T data)" << endl;
	}
	
	bool empty()const {
		return m_rear == m_head;
	}
	bool full() const {
		return m_head == (m_rear+1)%m_size;
	}
	void push(T data) {
		if(!full()){
			m_data[m_rear++] = data;
			m_rear %= m_size;
		}else{
			cout << "queue has been full" << endl;
			return ;
		}
	}
	void  pop(){
		if(!empty()){
			m_head++;
			m_head %= m_size;
		}else{
			cout << "queue has been empty" << endl;
			return ;
		}
	}
private:
	T *m_data;
	int m_rear;
	int m_head;
	int m_size;
};
int main(int argc,char* argv[]){
	Queue<int> q;
	cout << "q.empty()" << q.empty() << endl;
	q.push(1);
	cout << "q.empty()" << q.empty() << endl;
	for(int idx = 2;idx < 12; ++idx){
		q.push(idx);
	}
	cout << "q.full()" << q.full() << endl;
	q.pop();
	cout << "q.full()" << q.full() << endl;

}

