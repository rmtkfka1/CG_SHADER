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
		cout << "�Ҹ��� ȣ��" << endl;
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


	cout << "===============����====================" << endl;

	test_def();


	cout << "===============��====================" << endl;
}