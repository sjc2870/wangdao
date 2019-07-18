/*************************************************************************
 > File Name: ans4.cc
 > Author: SJC
 > Mail: 1123305914@qq.com 
 > Created Time: Thu 27 Jun 2019 05:20:48 AM PDT
 ************************************************************************/

#include <stdio.h>
#include<string>
#include<iostream>
using std::cout;
using std::endl;
using std::string;
using std::cin;
string arms[3] = {"sword","bomb","arrow"};
string red[5] = {"iceman","lion","wolf","ninja","dragon"};
string blue[5] = {"lion","dragon","ninja","iceman","wolf"};
class Man{
	//武士的基类
public:
	Man(int num,int life)
	:m_num(num)
	,m_life(life){
		
	}
private:
	int m_num;
	int m_life;
};

class Dragon  //武士Dragon
:public Man{
public:
	Dragon(int num,int life,int arm_num,double morale)
	:Man(num,life)
	,m_arm_num(arm_num)
	,m_morale(morale)  {    }

	void print(){
		cout << "It has a " << arms[m_arm_num] 
			 << ",and it's morale is " << m_morale 
			 << endl;
	}
private:
	int m_arm_num;  //武器的编号，具体名称到arm[]中取即可
	double m_morale;
};

class Ninja //武士Ninja
:public Man{
public:
	Ninja(int num,int life,int arm_num1,int arm_num2)
	:Man(num,life)
	,m_arm_num1(arm_num1)
	,m_arm_num2(arm_num2)  {   }

	void print(){
		cout << "It has a " << arms[m_arm_num1]
			 << ", and a " << arms[m_arm_num2]
			 << endl;
	}
private:
	int m_arm_num1;
	int m_arm_num2;
};

class Iceman   //武士Iceman
:public Man{
public:
	Iceman(int num,int life,int arm_num)
	:Man(num,life)
	,m_arm_num(arm_num)  {	}

	void print(){
		cout << "It has a " << arms[m_arm_num]
			 << endl;
	}
private:
	int m_arm_num;
};

class Lion   //武士Lion
:public Man{
public:
	Lion(int num,int life,int loyalty)
	:Man(num,life)
	,m_loyalty(loyalty) {    }

	void print(){
		cout << "It's loyalty is " << m_loyalty << endl;
	}
private:
	int m_loyalty;
};

class Wolf   //武士Wolf
:public Man{
public:
	Wolf(int num,int life)
	:Man(num,life)  {    }
};

class HeadQuaters{
public:
	HeadQuaters(int life)
	:m_life(life)
	,m_num(1) 
	,m_beg(1) 
	,m_brk(0){	}

	int getLife(){
		return m_life;
	}
	int getBeg(){
		return m_beg;
	}
	void print(const char* color,int life,const char* race,int num,int all){
		printf("%03d %s %s %d born with life %d,%d %s in %s headquater\n",\
			m_time,color,race,num,life,all,race,color);
	}
	int getNum(){
		return m_num;
	}
	int  produceIceman(const char* color,int num,int life,int arm_num){
		int ret = judge(color);
		if(ret==-1){
			return -1;
		}
		if(m_life>=life){
			Iceman iceman(num,life,arm_num);
			subLife(life);
			++m_all[0];
			print(color,life,"iceman",num,m_all[0]);
			iceman.print();
			++m_num;
			++m_time;
			return 0;
		} else{
			++m_brk;
			return -1;
		}
	}
	int produceLion(const char* color,int num,int life,int loyalty){
		int ret = judge(color);
		if(ret==-1){
			return -1;
		}
		if(m_life>=life){
			subLife(life);
			Lion lion(num,life,loyalty);
			++m_all[1];
			print(color,life,"lion",num,m_all[1]);
			lion.print();
			++m_num;
			++m_time;
			return 0;
		} else{
			++m_brk;
			return -1;
		}
	}
	int produceWolf(const char* color,int num,int life){
		int ret = judge(color);
		if(ret==-1){
			return -1;
		}
		if(m_life>=life){
			Wolf wolf(num,life);
			subLife(life);
			++m_all[2];
			print(color,life,"wolf",num,m_all[2]);
			++m_num;
			++m_time;
			return 0;
		} else{
			++m_brk;
			return -1;
		}
	}
	int  produceNinja(const char* color,int num,int life,int arm_num1,int arm_num2){
		int ret = judge(color);
		if(ret==-1) {
			return -1;
		}
		if(m_life>=life){
			Ninja ninja(num,life,arm_num1,arm_num2);
			subLife(life);
			++m_all[3];
			print(color,life,"ninja",num,m_all[3]);
			ninja.print();
			++m_num;
			++m_time;
			return 0;
		} else{
			++m_brk;
			return -1;
		}
	}
	int  produceDragon(const char* color,int num,int life,int arm_num,int morale){
		int ret = judge(color);
		if(ret==-1) {
			return -1;
		}
		if(m_life>=life){
			subLife(life);
			Dragon dragon(num,life,arm_num,morale);
			++m_all[4];
			print(color,life,"dargon",num,m_all[4]);
			dragon.print();
			++m_num;
			++m_time;
			return 0;
		} else{
			++m_brk;
			return -1;
		}
	}
private:
	void subLife(int life){
		m_life -=life;
	}

	int judge(const char* color){
		if(m_brk==3){
			m_beg = 0;
		}
		if(m_beg==0){
			if(m_flag==0){
				printf("%03d %s headquater stops making warrioirs\n",m_time,color);
				m_flag=1;
			}
			return -1;
		}
		return 0;
	}
private:
	int m_life;
	int m_num;   //它所生产的武士的编号，从1开始
	int m_beg;   //是否开始
	int m_brk;	 //
	int m_all[5] = {0};  // 0-4分别代表iceman,lion,wolf,njnia,dragon的数量
	int m_time = 0;		//时间
	int m_flag = 0;
};

int main(int argc,char* argv[]){
	int HeadQuatersLife = 0;
	cin >> HeadQuatersLife;

	int life[5] = {0};
	for(int i = 0;i<5;++i){
		//依次是dragon,ninja,iceman,lion,wolf的生命值
		cin >> life[i];
	}
	HeadQuaters red(HeadQuatersLife),blue(HeadQuatersLife);
	int i = 0;
	while(red.getBeg() || blue.getBeg()){
		++i;
		red.produceIceman("red",red.getNum(),life[2],red.getNum()%3);
		blue.produceLion("blue",blue.getNum(),life[3],blue.getLife()-life[3]);
		red.produceLion("red",red.getNum(),life[3],red.getLife()-life[3]);
		blue.produceDragon("blue",blue.getNum(),life[0],blue.getNum()%3,((double)(blue.getLife()-life[0]))/life[0]);
		red.produceWolf("red",red.getNum(),life[4]);
		blue.produceNinja("blue",blue.getNum(),life[1],blue.getNum()%3,(blue.getNum()+1)%3);
		red.produceNinja("red",red.getNum(),life[1],red.getNum()%3,(red.getNum()+1)%3);
	//	cout << "第" << i << "次循环 red.getBeg() = " << red.getBeg() << endl;
		blue.produceIceman("blue",blue.getNum(),life[2],blue.getNum()%3);
	//	cout << "第" << i << "次循环 blue.getBeg() = " << blue.getBeg() << endl;
		red.produceDragon("red",red.getNum(),life[0],red.getNum()%3,((double)(red.getLife()-life[0]))/life[0]);
	//	cout << "第" << i << "次循环 red.getBeg() = " << red.getBeg() << endl;
		blue.produceWolf("blue",blue.getNum(),life[4]);
	//	cout << "第" << i << "次循环 blue.getBeg() = " << blue.getBeg() << endl;
	}

}

