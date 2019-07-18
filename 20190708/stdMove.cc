/*************************************************************************
 > File Name: stdMove.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Sun 07 Jul 2019 08:46:18 PM PDT
 ************************************************************************/

#include <string.h>
#include<iostream>
using std::cout;
using std::endl;
class String{
public:
	String()
	:m_s(new char[1]()){}

	String(const char* s)
	:m_s(new char[strlen(s)+1]()){
		strcpy(m_s,s);
	}

	String (String &s)
	:m_s(new char[strlen(s.m_s)+1]()){
		strcpy(m_s,s.m_s);
		cout << "String(String&)" << endl;
	}

	void operator=(String s){
		if(s.m_s!=m_s){
			delete []m_s;
			m_s = new char[strlen(s.m_s)+1]();
			strcpy(m_s,s.m_s);
		}
	}
#if 1
	String (String &&s){
		m_s = s.m_s;
		s.m_s = nullptr;
		cout << "String(String&&)" << endl;
	}
#endif
	~String(){
		delete []m_s;
	}
	void print(){
		cout << m_s << endl;
	}
private:
	char* m_s;
};
String getStr(){
	String s("hello");
	return s;
}

int main(int argc,char* argv[]){
	String s = getStr();
	String s2 = s;
	s2.print();
	s.print();
}
