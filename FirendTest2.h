//
// Created by zenghui on 1/5/21.
//

#ifndef CBASE_FIRENDTEST2_H
#define CBASE_FIRENDTEST2_H

#include <iostream>

using namespace std;

class AParent;

class FirendTest2 {
public:
    FirendTest2();

    void test1();

    void test2();

private:
    AParent *frendParent;
};

class AParent {
    /**
     * 指定友元函数
     */
    friend void FirendTest2::test2();

public:
    int age = 10;

    AParent() {
        cout << "调用AParent构造函数" << endl;
    }

private:
    char *name = "honhon";
};

FirendTest2::FirendTest2() {
    frendParent = new AParent;
}

/**
 * 非友元函数无法调用内部私有属性
 */
void FirendTest2::test1() {
//    cout << "友元函数调用private name" << frendParent->name << endl;
    cout << "友元函数调用public age" << frendParent->age << endl;
}

/**
 * 友元函数能够调用私有属性
 */
void FirendTest2::test2() {
    cout << "友元函数调用private name" << frendParent->name << endl;
    cout << "友元函数调用public age" << frendParent->age << endl;
}


#endif //CBASE_FIRENDTEST2_H
