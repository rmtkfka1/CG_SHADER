#include "pch.h"
#include <memory>
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
        cout << "vec ÀÇÁÖ¼Ò" << endl;
        for (int i = 0; i < vec.size(); ++i)
        {
            cout << vec[i] << endl;
        }
    }
    std::vector<int*> vec;

    std::vector<int*> returnvec() { return vec; }
};

float* test()
{
    float a[2] = { 1.0f,2.0f };

    return a;
}

int main() {
    
    unique_ptr<int> a(new int(5));

    unique_ptr<int> b = move(a);

    return 0;
}
