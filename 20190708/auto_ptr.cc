/*************************************************************************
 > File Name: auto_ptr.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Mon 08 Jul 2019 02:23:45 AM PDT
 ************************************************************************/

#include<iostream>
#include <memory>
using std::auto_ptr;
using std::cout;
using std::endl;
class Point{
public:
	Point(int x=0,int y=0)
	:m_x(x)
	,m_y(y){
	}
	void print() const{
		cout << "(" << m_x
			 << "," << m_y
			 << ")" << endl;
	}
	~Point(){
		
	}
	friend std::ostream& operator<<(std::ostream& os,const Point &p);
private:
	int m_x;
	int m_y;
};
std::ostream& operator<<(std::ostream& os,const Point &p){
	os << "(" << p.m_x
	   << "," << p.m_y
	   << ")" << endl;
	return os;
}
int main(int argc,char* argv[]){
	Point *pp = new Point(1,2);
	auto_ptr<Point> ap(pp);
	cout << "*ap = " << *ap << endl;
	cout << "ap.get = " << ap.get() << endl;
	cout << "p = " << pp << endl;

	auto_ptr<Point> ap2(ap);

	cout << "*ap2 " << *ap2 << endl;
	cout << "ap2.get " << ap2.get() << endl;
	//cout << "*ap" << *ap << endl;
	//cout << "ap.get" << ap.get() << endl;
	auto_ptr<Point> ap3(new Point(3,4));
	ap3 = ap2;
	cout << "*ap3 = " << *ap3 << endl;
	cout << "ap3.get = " << ap3.get() << endl;
	//cout << "*ap2 = " << *ap2 << endl;
	//cout << "ap2.get = " << ap2.get() << endl;
}

