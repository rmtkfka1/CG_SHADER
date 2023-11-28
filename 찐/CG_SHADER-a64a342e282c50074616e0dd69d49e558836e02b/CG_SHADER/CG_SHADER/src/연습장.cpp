#include "pch.h"


class test
{

public:
	test()
	{
		ptr = make_shared<int>(30);
	}

	~test()
	{
		cout << "소멸자 호출" << endl;
	}


	void print()
	{
		cout << *ptr << endl;
	}


private:

	shared_ptr<int> ptr;


};


void test_def()
{
	shared_ptr<test> p1 = make_shared<test>();

	p1->print();

}



int main()
{


	cout << "===============시작====================" << endl;

	test_def();


	cout << "===============끝====================" << endl;
}