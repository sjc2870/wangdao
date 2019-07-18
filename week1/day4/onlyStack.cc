/*************************************************************************
 > File Name: onlyStack.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Sun 23 Jun 2019 02:30:03 AM PDT
 ************************************************************************/
//new 一个对象时有三个过程，1调用operator new，分配一片未初始化的区域
//2调用构造函数  3 返回指向新分配并构造的构造函数对象的指针
//只能生成栈类型的对象，那么把operator new放入private区域，就不能在类外使用new来生成堆类型的对象了
#include<iostream>
using std::cout;
using std::endl;

class Stu{
public:
	Stu (int id=0)
	:m_id(id)
	{}
private:
	void* operator new(size_t );
	int m_id;
};

int main(int argc,char* argv[]){
	Stu s1;
	//Stu *s2 = new Stu();  报错  不能通过编译
}

