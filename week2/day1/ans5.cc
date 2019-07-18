/*************************************************************************
  > File Name: ans5.cc
  > Author: SJC
  > Mail: 1123305914@qq.com 
  > Created Time: Mon 24 Jun 2019 06:22:36 AM PDT
 ************************************************************************/

#include <string.h>
#include<iostream>
using std::cout;
using std::endl;

class String{
	public:
		String()//，默认构造函数
			:m_ptr(new char[1]()){ }

		String (const char* ptr)//构造函数
			:m_ptr(new char[strlen(ptr) + 1] ()){
				strcpy(m_ptr,ptr);
				cout << "String (const char*)" << endl;
			}

		String (const String& s)//复制构造函数
			:m_ptr(new char[strlen(s.m_ptr)+1]()){
				strcpy(m_ptr,s.m_ptr);
			}

		~String(){//析构函数
			delete [] m_ptr;
			cout << "~String()" << endl;
		}

		String &operator=(const String& s){
			//赋值运算符函数
			if(&s!=this){
				delete [] m_ptr;
				m_ptr = new char[strlen(s.m_ptr)+1] ();
				strcpy(m_ptr,s.m_ptr);
			}
			return *this;
		}

		String &operator=(const char* s){
			//赋值运算符函数
			String tmp(s);
			*this = tmp;
			return *this;
#if 0
			delete [] m_ptr;
			m_ptr = new char[strlen(s)+1]();
			strcpy(m_ptr,s);
			return *this;
#endif
		}
		void print(){
			cout << m_ptr << endl;
		}

		String &operator+=(const String &s){
			//注意需要重新分配内存
			char * tmp = new char[strlen(s.m_ptr)+strlen(m_ptr)+1]();
			sprintf(tmp,"%s%s",m_ptr,s.m_ptr);
			delete [] m_ptr;
			m_ptr = tmp;
			return *this;
		}

		String &operator+=(const char* s){
			//有错误，但不知道哪里错了  
			String tmp(s);
			*this += tmp;
			return *this;
		}

		char &operator[](int idx){
			static char s = '\0';
			if(idx>=0 && idx <strlen(m_ptr)){
				return m_ptr[idx];
			}else{
				return s;
			}
		}

		const char&operator[](int idx)const {
			static char s = '\0';
			if(idx>=0 && idx <strlen(m_ptr)){
				return m_ptr[idx];
			}else{
				return s;
			}
		}

		std::size_t size() const {
			return strlen(m_ptr);
		}

		const char* c_str() const{
			return m_ptr;
		}
		friend bool operator==(const String &, const String &);
		friend bool operator!=(const String &, const String &);

		friend bool operator<(const String &, const String &);
		friend bool operator>(const String &, const String &);
		friend bool operator<=(const String &, const String &);
		friend bool operator>=(const String &, const String &);

		friend std::ostream &operator<<(std::ostream &os, const String &s);
		friend std::istream &operator>>(std::istream &is, String &s);
	private:
		char* m_ptr;
};

bool operator==(const String& s1,const String &s2){
	return strcmp(s1.m_ptr,s2.m_ptr)==0?true:false;
}

bool operator!=(const String& s1,const String &s2){
	return strcmp(s1.m_ptr,s2.m_ptr)!=0?true:false;
}

bool operator<(const String& s1,const String &s2){
	return strcmp(s1.m_ptr,s2.m_ptr)<0?true:false;
}

bool operator>(const String& s1,const String &s2){
	return strcmp(s1.m_ptr,s2.m_ptr)>0?true:false;
}
bool operator<=(const String& s1,const String &s2){
	return strcmp(s1.m_ptr,s2.m_ptr)<=0?true:false;
}
bool operator>=(const String& s1,const String &s2){
	return strcmp(s1.m_ptr,s2.m_ptr)>=0?true:false;
}

std::ostream &operator<<(std::ostream &os,const String &s){
	os << s.m_ptr;
	return os;
}

std::istream &operator>>(std::istream &is,String &s){
	is >> s.m_ptr;
	return is;
}

String operator+(const String &s1,const String &s2){
	char *tmp = new char[s1.size()+s2.size()+1]();
	sprintf(tmp,"%s%s",s1.c_str(),s2.c_str());
	String s (tmp);
	return s;
}

#if 1
String operator+(const String &s1,const char* s2){
	char *tmp = new char[s1.size()+strlen(s2)+1]();
	sprintf(tmp,"%s%s",s1.c_str(),s2);
	String s(tmp);
	return s;
}
String operator+(const char* s1,const String& s2){
	char *tmp = new char[strlen(s1)+s2.size()+1]();
	sprintf(tmp,"%s%s",s1,s2.c_str());
	String s (tmp);
	return s;
}
#endif
int main(int argc,char* argv[]){
	String s1;//默认构造函数测试
	s1.print();

	String s2 = "hi!";//构造函数测试
	s2.print();

	String s3 = s2;//复制构造函数测试
	s3.print();

	s1 = s3;//赋值运算符函数测试
	s1.print();

	s1 = "hello";//赋值运算符函数测试
	s1.print();

	s1+=s2;
	s1.print();
	s1+="haha";
	s1.print();

	for(int i = 0;i<s1.size();++i){
		//测试[]运算符重载  OK
		cout << s1[i] << endl;
	}
	
	cout << "s1 = " << s1 << endl;

	String s4 = s1 + s2;
	cout << s4 << endl;
	
	s1 = s2 + "haha";
	cout << s1 << endl;
}

