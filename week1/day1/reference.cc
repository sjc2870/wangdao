#include <iostream>

using std::cout;
using std::endl;
int&test0();
int main(){
	int nums[5] = {1,2,3,4,5};
	int a = 0;
	int &b = a;
	b = 1;
	cout << "a = " << a << endl;
	int & c = test0();
	free(&c);
	nums[test0()] = 10;//返回的引用可以作为做值
	cout << "nums[0] = " << nums[0] << endl;
}

int &test0(){
	int a = 10;
	int *b = (int*)calloc(1,sizeof(int));
	//return a;//报错：因为不能返回局部变量的引用
	return *b;//不要轻易返回堆空间的引用，非常容易内存泄露
}
