#pragma once


class Line{
	class Impline;
public:
	Line(int ,int,int,int);
	~Line();
	void print();
private:
	Impline *m_pimpline;
};
