#include <iostream>

using std::cout;
using std::endl;

int main(){
	int *b = new int(10);
	cout << "b = " << *b << endl;
	delete b;
	int *a = new int[2]{0,1};
	cout << "a[0] = " << a[0] << "\na[1] = " << a[1] << endl;
	delete [] a;
}
