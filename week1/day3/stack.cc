/*************************************************************************
 > File Name: stack.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Wed 19 Jun 2019 12:49:26 AM PDT
 ************************************************************************/

#include<iostream>
using std::cout;
using std::endl;

class Stack{
public:
	Stack()//构造函数
	:m_arr{10,0},
	m_top(-1){
		cout << "This is create func " << endl;
	}
	void push(int i){//压栈
		if(m_top==9){
			cout << "error:stack has been full" << endl;
		}else{
			m_arr[++m_top] = i;
		}
	}
	void pop(){//弹栈
		if(m_top==-1){
			cout << "error:stack has been empty" << endl;
		}else{
			m_top--;
		}
	}
	int top(){
		return m_arr[m_top];
	}
	bool empty(){
		return m_top==-1?true:false;
	}
	bool full(){
		return m_top==9?true:false;
	}
private:
	int m_arr[10];
	int m_top;
};

int main(int argc,char* argv[]){
	Stack stk;
	stk.push(10);
	stk.push(12);
	stk.push(14);
	cout << stk.top() << endl;
	stk.pop();
	cout << stk.top() << endl;
}

