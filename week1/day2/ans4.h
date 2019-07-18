#include <iostream>

using std::cout;
using std::endl;

class String{
public:
	String();
	String(const char* pstr);
	String(const String& rhs);
//	String& operator=(const String& rhs);
	~String();

	void print();

private:
	char* m_pstr;
};
