//
// Created by zenghui on 1/5/21.
//

#ifndef CBASE_NEWOPERATOR_H
#define CBASE_NEWOPERATOR_H

#include <iostream>
#include <time.h>

using namespace std;

class CTestClass {
    char m_chBuf[4096];
};

char buf[4100];

class CTestClass1 {
    char m_chBuf[4096];
public:
    void *operator new(size_t size) {
        return (void *) buf;
    }

    void operator delete(void *p) {

    }
};

void testNewOperator() {
    clock_t count = clock();
    for (unsigned int i = 0; i < 0x5fffff; i++) {
        CTestClass *p = new CTestClass;
        delete p;
    }
    cout << "没有重写new运算符耗时： " << clock() - count << " sec" << endl;
    count = clock();
    for (unsigned int i = 0; i < 0x5fffff; i++) {
        CTestClass1 *p = new CTestClass1;
        delete p;
    }
    cout << "重写new运算符耗时：" << clock() - count << " sec" << endl;
}

#endif //CBASE_NEWOPERATOR_H
