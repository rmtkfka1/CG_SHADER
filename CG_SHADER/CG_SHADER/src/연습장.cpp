#include "pch.h"


#include <iostream>
#include <vector>

class test {
public:
    test() {
        for (int i = 0; i < 5; ++i) {
            int* ptr = new int(i);
            vec.push_back(ptr);
        }
    }

    void print()
    {
        cout << "vec 의주소" << endl;
        for (int i = 0; i < vec.size(); ++i)
        {
            cout << vec[i] << endl;
        }
    }
    std::vector<int*> vec;

    std::vector<int*> returnvec() { return vec; }
};

int main() {
    test a;
    std::vector<int*> v = a.returnvec();

    cout << "메인에서 v의주소" << endl;

    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << endl;
    }

    a.print();


    return 0;
}
