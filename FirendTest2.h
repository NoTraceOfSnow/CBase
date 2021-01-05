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
    void test2();

private:
    AParent *frendParent;
};

class AParent {
    friend void FirendTest2::test2();

public:
    int age = 10;

    AParent() {
        cout << "调用AParent构造函数" << endl;
    }

private:
    char *name = "honhon";
};

void FirendTest2::test2() {
    frendParent = new AParent;
    cout << "友元函数调用private name" << frendParent->name << endl;
    cout << "友元函数调用public age" << frendParent->age << endl;
}


#endif //CBASE_FIRENDTEST2_H
