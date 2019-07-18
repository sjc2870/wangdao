/*************************************************************************
 > File Name: single.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Wed 19 Jun 2019 12:09:15 AM PDT
 ************************************************************************/

#include<iostream>
using std::cout;
using std::endl;

class Single{
public:
	static Single* getInstance(){
		if(m_pSingle==nullptr){
			m_pSingle = new Single();
		}
		return m_pSingle;
	}

	static void destory(){
		if(m_pSingle!=nullptr){
			delete m_pSingle;
			m_pSingle = NULL;
			cout << "This is destory" << endl;
		}
	}

	Single (const Single *s)
	{
	}
private:
	Single(){//构造函数
		cout << "single()" << endl;
	}

	~Single(){
		
	}

	static Single* m_pSingle;
	int m_data;
};
Single* Single::m_pSingle = nullptr;
int main(int argc,char* argv[]){
	Single* s1 = Single::getInstance();
	Single* s2 = Single::getInstance();
	cout << s1 << endl;
	cout << s2 << endl;
	Single::destory();
	Single::destory();
}

