#include <iostream>

using std::cout;
using std::endl;

int main(){
	//const int a;  error:常量必须初始化
	int num = 10;
	int a = 100;
	const int * p = &num;
	p = &a;
	//*p = 1; error   p是常量指针，不能对指向的对象赋值
	int * const p2 = &num;
	*p2 = 100;
	//p2 = &a;  error  p是指针常量，除了初始化外不能对指针再赋值
}
