#include "pch.h"



class test
{

public:


	~test()
	{
		cout << "º´½Å»õ³¢" << endl;
	}

	int a[10] = 
	{
		1,2,3,4,5,6,7,8,9,0
	};



};

vector<test> v;

void func()
{
	test a;

	cout << &a << endl;

	v.push_back(a);
}


int main()
{

	func();

	cout << &v[0] << endl;
}
