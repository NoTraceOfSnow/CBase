//
// Created by zenghui on 1/5/21.
//

#ifndef CBASE_FRENDTEST_H
#define CBASE_FRENDTEST_H

#include <iostream>

using namespace std;

/**
 * 测试友元类
 * 友元类不能被继承，即友元关系不能被继承
 */
class AParent {
    /**
     * 指定友元类
     */
    friend class FrendTest;

public:
    int age = 10;

    AParent() {

    }

private:
    char *name = "honhon";

};

class FrendTest {

public:
    void test() {
        cout << "友元类，调用私有属性：" << frendParent.name << endl;
        cout << "友元类，调用共有属性：" << frendParent.age << endl;
    }

private:
    AParent frendParent;
};

#endif //CBASE_FRENDTEST_H
