//
// Created by zenghui on 1/5/21.
//

#ifndef CBASE_STRUCTANDCLASS_H
#define CBASE_STRUCTANDCLASS_H

#include <iostream>

using namespace std;

struct StructSize {

};

struct StructSize1 {
    int a;
    char b;
};

class StructAndClass {

};

class StructAndClass1 {
public:
    int a;
    /**
     * 静态属性存放在静态区，对StructAndClass1大小没影响。
     * 此时大小还是8
     */
    static int c;
private:
    char b;

    /**
     * 普通方法存放在代码段，也不会对struct产生影响
     */
    void func() {

    }
};

class StructAndClass2 {
    /**
     *  为是什么当有virtual修饰的方法时，StructAndClass2会变为8
     *  由于virtual的时候
     *  C++会默认建立一个数组指针vtable存放virtual函数。
     *  当子类继承并重写该函数时，该函数就会把指针指向子类重写的对应函数
     *  注意纯虚函数必须 有=0
     */
    virtual void test() = 0;
};

class StructAndClass3 {
public:
    int age = 10;

    virtual void test() = 0;

    void test1() {
        cout << "普通函数  调用父类test1函数实现" << endl;
    }
};

class StructAndClass4 : public StructAndClass3 {
    void test() {
        cout << "纯虚函数  调用子类test函数实现" << endl;
    }

    void test1() {
        cout << "普通函数  调用子类test1函数实现" << endl;
    }
};

void testVirtual() {
    cout << "测试纯虚函数与普通函数区别" << endl;
    StructAndClass3 *structAndClass3 = new StructAndClass4;
    structAndClass3->test();
    structAndClass3->test1();
    cout << "继承父类后子类的大小：" << sizeof(StructAndClass4) << endl;
    cout << "总结：" << endl;
    cout << "继承父类后子类的大小与父类的相同，其属性值是拷贝过来的" << endl;
    cout << "StructAndClass3 *structAndClass3 = new StructAndClass4;" << endl;
    cout << "structAndClass3->test1(); 如果调用的是普通函数，那么会调用父类的普通函数，不会调用子类的" << endl;
    cout << "structAndClass3->test(); 如果调用的是纯虚函数，那么会调用子类重写的函数" << endl;
}


#endif //CBASE_STRUCTANDCLASS_H
