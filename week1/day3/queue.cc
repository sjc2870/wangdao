/*************************************************************************
 > File Name: queue.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Wed 19 Jun 2019 01:15:30 AM PDT
 ************************************************************************/

#include<iostream>
using std::cout;
using std::endl;

class Queue{
public:
	Queue ()//构造函数
	:m_head(0)
	,m_tail(0)
	,m_size(0){	}

	void push(int i) {
		m_arr[m_head++] = i;
		m_size++;
	}
	void pop(){
		m_tail++;
		m_size--;
	}
	int front(){
		return m_arr[m_head];
	}
	int back(){
		return m_arr[m_tail];
	}
	bool empty(){
		return m_size==0?true:false;
	}
	bool full(){
		return m_size==10?true:false;
	}
private:
	int m_arr[10];
	int m_head;
	int m_tail;
	int m_size;
};
int main(int argc,char* argv[]){
	Queue q;
	for(int i=0;i<10;++i){
		q.push(i+1);
	}
	cout << q.front() << "," 
		 << q.back() << endl;
	q.pop();
	cout << q.front() << ","
		 << q.back() << endl;

}

