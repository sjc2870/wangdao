/*************************************************************************
 > File Name: CowString.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Wed 26 Jun 2019 02:24:08 AM PDT
 ************************************************************************/

#include <string.h>
#include<iostream>
using std::cout;
using std::endl;

class CowString{
	class CharProxy{
	public:
		CharProxy(CowString &self,int idx)
		:m_self(self)
		,m_idx(idx){  }
		
		friend std::ostream & operator << (std::ostream& os,const CharProxy &rhs);
		char &operator=(const char &c);
	private:
		CowString &m_self;
		int m_idx;
	};
public:
	CowString()
	:m_ptr(new char[1+4]()+4){
		cout << "CowString()" << endl;
		increseRefCnt();
	}

	CowString(const char* s)
	:m_ptr(new char[strlen(s)+1+4]()+4){
		strcpy(m_ptr,s);
		initRefCnt();
		cout << "CowString(const char*)" << endl;
	}
	void print(){
		cout << "RefCnt = " << *(int*)(m_ptr-4)  
			 << ",string = " << m_ptr << endl;
	}
	~CowString(){
		release();
	}
	CowString(const CowString &s)
	:m_ptr(s.m_ptr){
		increseRefCnt();
		cout << "CowString(const CowString&)" << endl;
	}
	CharProxy operator[](int idx){
		return CharProxy(*this,idx);
	}
	const char* c_str(){
		return m_ptr;
	}

	int size(){
		return strlen(m_ptr);
	}
	int refCnt(){
		return *(int*)(m_ptr-4);
	}
friend std::ostream & operator << (std::ostream& os,const CharProxy &rhs);
friend std::ostream & operator << (std::ostream& os,const CowString &s);
private:
	void release(){
		decreseRefCnt();
		if(refCnt()==0){
			delete [] (m_ptr-4);
			cout << "~CowString" << endl;
		}
	}
	void initRefCnt(){
		*(int*)(m_ptr-4) = 1;
	}
	void increseRefCnt(){
		++*(int*)(m_ptr-4);
	}
	void decreseRefCnt(){
		--*(int*)(m_ptr-4);
	}
private:
	char* m_ptr;
};

 char& CowString::CharProxy::operator=(const char &c){
	 //写时复制
	if(c==m_self.m_ptr[m_idx] || m_idx<0 || m_idx>=m_self.size()){
		static char  non = '\0';
		return non;
	}
	
	if(m_self.refCnt()>1){
		m_self.decreseRefCnt();

		char* tmp = new char[m_self.size()+5]()+4;
		strcpy(tmp,m_self.m_ptr);
		m_self.m_ptr = tmp;
		m_self.initRefCnt();
	}
	m_self.m_ptr[m_idx] = c;
	return m_self.m_ptr[m_idx];
}
std::ostream & operator << (std::ostream& os,const CowString::CharProxy &rhs){
	os << rhs.m_self.m_ptr[rhs.m_idx];
	return os;
}

std::ostream & operator << (std::ostream& os,const CowString &s){
	os << s.m_ptr;
	return os;
}
int main(int argc,char* argv[]){
	CowString s0 = "hello";
	CowString s1 = s0;
	s0.print();
	printf("s0.address = %p\n",s0.c_str());
	s1.print();
	printf("s1.address = %p\n",s1.c_str());
	
	cout << endl << "执行写操作" << endl;
	s0[0] = 'H';
	cout << "s0 = " << s0 << endl;
	cout << "s0的引用计数是" << s0.refCnt() << endl;
	printf("s0.address = %p\n",s0.c_str());
	cout << "s1 = " << s1 << endl;
	cout << "s1的引用计数是" << s1.refCnt() << endl;
	printf("s1.address = %p\n",s1.c_str());

	CowString s2 = s0;
	cout << "s2 = " << s2 << endl;
	cout << "s2的引用计数是" << s2.refCnt() << endl;
	printf("s2.address = %p\n",s2.c_str());
	cout << "s0 = " << s0 << endl;
	cout << "s0的引用计数是" << s0.refCnt() << endl;
	printf("s0.address = %p\n",s0.c_str());

}

