#include <iostream>

int add(int a,int b,int c){
	return a+b+c;
}

int add(int a,int b){
	return a+b;
}

void add(int a,double b){
	
}
//   只有返回值不同的函数不能被重载
//int add(int a,double b){
//	return a+b;
//}
#ifdef __cplusplus
extern "C"{
#endif
int add(){
	return 0;
}
#ifdef __cplusplus
}
#endif
using std::cout;
using std::endl;
int main(){
	cout << "add() = "<< add() << endl;;
}
