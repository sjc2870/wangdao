/*************************************************************************
 > File Name: ans2.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Mon 08 Jul 2019 01:08:39 AM PDT
 ************************************************************************/

#include <string.h>
#include <vector>
#include<iostream>
using std::cout;
using std::endl;
using namespace std;
class String {
public:
	String()
	:m_pstr(new char[1]()){
		cout << "String()" << endl;
	}
	String(const char*s)
	:m_pstr(new char[strlen(s)+1]()){
		strcpy(m_pstr,s);
		cout << "String(const char*)" << endl;
	}

	String (String &s)
	:m_pstr(new char[strlen(s.m_pstr)+1]()){
		strcpy(m_pstr,s.m_pstr);
		cout << "String(String&)" << endl;
	}
	String& operator=(String &s){
		if(m_pstr!=s.m_pstr){
			delete []m_pstr;
			m_pstr = new char[strlen(s.m_pstr)+1]();
			strcpy(m_pstr,s.m_pstr);
		}
		cout << "String& operator=(String &)" << endl;
		return *this;
	}
	char& operator[](int idx){
		if(idx>=0 && idx <strlen(m_pstr)){
			return m_pstr[idx];
		}else{
			cout << "idx out of range" << endl;
			static char c ='\0';
			return c;
		}
	}
#if 1
	String(String &&s)
	:m_pstr(s.m_pstr){
		s.m_pstr = nullptr;
		cout << "String(String&&)" << endl;
	}
	String& operator=(String &&s){
		if(m_pstr!=s.m_pstr){
			delete []m_pstr;
			m_pstr = s.m_pstr;
			s.m_pstr = nullptr;
		}
		cout << "String& operator=(String &&)" << endl;
		return *this;
	}
#endif
	void print(){
		cout << m_pstr << endl;
	}
	~String(){
		if(m_pstr){
			delete []m_pstr;
		}
		cout << "~String()" << endl;
	}
	friend std::ostream& operator<<(std::ostream&,const String &s);
private:
	char* m_pstr;
};
std::ostream& operator<<(std::ostream& os,const String &s){
	os << s.m_pstr;
	return os;
}
String getStr(const char* s){
	String str(s);
	return str;
}
int test0(void){
	vector<String> svec;
	svec.push_back("hello");
	return 0;
}
void test1(){
	String s = "hello";
	String s2("world");
	s2 = std::move(s);
	s2.print();
	s.print();
}
int main(int argc,char* argv[]){
	test1();
}

