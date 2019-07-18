/*************************************************************************
 > File Name: anser1-2.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Thu 27 Jun 2019 02:17:05 AM PDT
 ************************************************************************/

#include<iostream>
using std::cout;
using std::endl;
#define PI (3.1415926)
class Circle{
public:
	Circle()
	:m_r(0){
		cout << "Circle()" << endl;
	}
	Circle(double r)
	:m_r(r){
		cout << "Circle(double)" << endl;
	}
	double getArea(){
		return PI*m_r*m_r;
	}
	double getPerimeter(){
		return 2*PI*m_r;
	}
	void show(){
		cout << "r = " << m_r 
			 << ",area = " << getArea()
			 << ",perimeter = " << getPerimeter() << endl;
	}
private:
	double m_r;
};

class Cylinder
:public Circle{
public:
	Cylinder(double r,double h)
	:Circle(r)
	 ,m_height(h){
	 	cout << "Cylinder(double,double)" << endl;
	 }

	double getVolume(){
		return getPerimeter()*m_height;
	}
	void showVolume(){
		cout << "Volume = " << getVolume() << endl;
	}
private:
	double m_height;
};

int main(int argc,char* argv[]){
	Cylinder c1(3,5);
	c1.show();
	c1.showVolume();
}

