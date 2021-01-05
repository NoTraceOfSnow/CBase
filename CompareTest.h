//
// Created by zenghui on 1/5/21.
//

#ifndef CBASE_COMPARETEST_H
#define CBASE_COMPARETEST_H

#include <iostream>

using namespace std;

template<class T> //声明一个模板，虚拟类型名为T。注意：这里没有分号。

class CompareTest {
//类模板名为Compare

public :

    CompareTest(T a, T b) {
        x = a;
        y = b;
    }

    T max() {
        return (x > y) ? x : y;
    }

    T min() {
        return (x < y) ? x : y;
    }

private :
    T x, y;
};

int testCompare() {
    cout << "测试编译时多态" << endl;
    CompareTest<int> c1(5, 6);
    CompareTest<float> c2(3.4, 10.2);
    cout << "测试编译时多态结束" << endl;
    return 0;
}

#endif //CBASE_COMPARETEST_H
