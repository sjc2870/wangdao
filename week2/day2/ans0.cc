/*************************************************************************
 > File Name: ans0.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Wed 26 Jun 2019 12:33:00 AM PDT
 ************************************************************************/
#include "ans0.h"
#include<iostream>
using std::cout;
using std::endl;

class Line::Impline{
	class Point{
	public:
		Point(int ix = 0,int iy = 0)
		:m_ix(ix)
		,m_iy(iy){
			cout << "Point(int,int)" << endl;
		}
		~Point(){
			cout << "~Point()" << endl;
		}

		void print() const {
			cout << "(" << m_ix
				 << "," << m_iy
				 << ")";
		}
	private:
		int m_ix;
		int m_iy;
	};
public:
	Impline(int x1,int y1,int x2,int y2)
	:m_p1(x1,y1)
	,m_p2(x2,y2){
		cout << "Impline(int,int,int,int)" << endl;
	}

	~Impline(){
		cout << "~Impline()" << endl;
	}

	void print() const{
		m_p1.print();
		cout << " --> ";
		m_p2.print();
		cout << endl;
	}
private:
	Point m_p1;
	Point m_p2;
};

Line::Line(int x1,int y1,int x2,int y2)
:m_pimpline(new Impline(x1,y1,x2,y2)){
	cout << "Line(int,int,int,int)" << endl;
}
Line::~Line(){
	delete m_pimpline;
	cout << "~Line(int,int,int,int)" << endl;
}
void Line::print(){
	m_pimpline->print();
}
