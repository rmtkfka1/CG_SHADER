#include "pch.h"
#include <memory>
#include <iostream>
#include <vector>


class test
{


public:

	test(){};
	~test()
	{
		cout << "�Ҹ��� ȣ��" << endl;
	}

	int* ptr = new int(10);
};

vector<test*> v;


void hey()
{

}

int main()
{


}
