#include <iostream>

using std::cout;
using std::endl;
int num = 1;
namespace sjc{
	void display();
	int num = 100;
}
namespace wd{
	int num = 10;
	void display(int num){
		cout << "wd::display" << endl;
		sjc::display();
		cout << "::num = " << ::num << endl;
		cout << "wd::num = " << wd::num << endl;
		cout << "sjc::num = " << sjc::num << endl;
		cout << "num = " << num << endl;
	}
}

namespace sjc{
	void display(){
		cout << "sjc::display" << endl;
	}
}

int main(){
	int a = 1000;
	wd::display(a);

}
