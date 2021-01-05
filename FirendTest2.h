//
// Created by zenghui on 1/5/21.
//

#ifndef CBASE_FIRENDTEST2_H
#define CBASE_FIRENDTEST2_H

#include "FirendParent.h"
#include <iostream>

using namespace std;

class FirendTest2 {
public:
    void test2() {
        cout << "友元函数，调用私有属性：" << frendParent.name << endl;
        cout << "友元函数，调用共有属性：" << frendParent.age << endl;
    }

private:
    FirendParent frendParent;
};


#endif //CBASE_FIRENDTEST2_H
