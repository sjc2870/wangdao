/*************************************************************************
 > File Name: ans3.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Thu 27 Jun 2019 02:34:53 AM PDT
 ************************************************************************/
#include <string.h>
#include<iostream>
using std::cout;
using std::endl;

class Person{
public:
	Person(char* name,int age)
	:m_age(age){
		cout << "Person(char*,int)" << endl;
		strcpy(m_name,name);
	}

	void display(){
		cout << "name = " << m_name 
			 << ",age = " << m_age ;
	}
	~Person(){
		cout << "~Person()" << endl;
	}
private:
	char m_name[20] = {0};
	int m_age;

};

class Employee
:public Person{
public:
	Employee(char* name,int age,char* depar,double salary)
	:Person(name,age)
	,m_salary(salary){
		strcpy(m_depar,depar);
		cout << "Employee(char*,int,char*,double)" << endl;
	}
	~Employee(){
		cout << "~Employee()" << endl;
	}
	void display(){
		Person::display();
		cout << ",department = " << m_depar 
			 << ",salary = " << m_salary 
			 << endl;
	}
	double getSalary(){
		return m_salary;
	}
private:
	char m_depar[30];
	double m_salary;
};
int main(int argc,char* argv[]){
	Employee e1((char*)"sun",20,(char*)"x",6000);
	e1.display();
	Employee e2((char*)"wang",21,(char*)"y",7000);
	e2.display();
	Employee e3((char*)"li",22,(char*)"z",8000);
	e3.display();

	double aveSalary = 0;
	aveSalary = (e1.getSalary()+e2.getSalary()+e3.getSalary())/3;
	cout << "average salary = " << aveSalary << endl;
}

