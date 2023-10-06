#include "pch.h"


vector<int> v;



class test
{

public:

	static test* GetInstance()
	{
		static test my;
		return &my;
	}


	void hello() { cout << "hello" << endl; }


};


int main()
{

	test::GetInstance()->hello();

}
