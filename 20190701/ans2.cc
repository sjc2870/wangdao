/*************************************************************************
 > File Name: ans2.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Mon 01 Jul 2019 05:44:21 AM PDT
 ************************************************************************/
#include <string.h>
#include<iostream>
using std::cout;
using std::endl;

class Point{
public:
	Point(int x=0,int y = 0)
	:m_x(x)
	,m_y(y){
		
	}
	int getX(){
		return m_x;
	}
	int getY(){
		return m_y;
	}
private:
	int m_x;
	int m_y;
};

class Computer{
public:
	Computer(const char* brand,int price)
	:m_brand(new char[strlen(brand)+1]())
	,m_price(price){
		strcpy(m_brand,brand);
	}
	~Computer(){
		delete [] m_brand;
	}
	const char* getBrand()const{
		return m_brand;
	}
	int getPrice()const {
		return m_price;
	}
private:
	char *m_brand;
	int m_price;
};

template<class T>
class Single{
public:
	template<class... Args >
	static T* getInstance(Args... args){
		if(m_pInstance==nullptr){
			m_pInstance = new T(args...);
		}
		return m_pInstance;
	}
	void destory(){
		if(m_pInstance){
			delete m_pInstance;
		}
	}
private:
	Single(){ }
	~Single() { }
	static T*m_pInstance;
};

template<class T>
T* Single<T>::m_pInstance = nullptr;
int main(int argc,char* argv[]){
	Computer *p1 = Single<Computer>::getInstance("Xiaomi",6666);
	cout << "p1.brand = " << p1->getBrand() << endl;
	cout << "p1.price = " << p1->getPrice() << endl;
	Point *p3 = Single<Point>::getInstance(1,2);
	cout << "p3.x = " << p3->getX() << endl;
	cout << "p3.y = " << p3->getY() << endl;
}

