//
// Created by zenghui on 1/5/21.
//

#ifndef CBASE_TEMPLATETEST_H
#define CBASE_TEMPLATETEST_H

#include "BaseHeader.h"

class Child {
public:
    void testChild() {
        cout << "泛型调用child方法" << endl;
    }
};

template<typename T>
class Base {
public:
    T m_A;

    Base(T mA) {
        this->m_A = mA;
    };

    void funC() {
        m_A.testChild();
    }
};

template<typename T, typename R>
class Son : public Base<T> {
private:
    R m_b;
};



//void testFun(T a){
//
//}

void testTemplate() {
    cout << "-----------测试template函数模板----------" << endl;

    Base<int> base(10);
//    base.funC();
    Child child;
    Base<Child> base1(child);
    base1.funC();
    cout << "写法 : template<typename T, typename R>， template<class T, class R>" << endl;
    cout << "调用 : 需要确定类型，否则会出现报错 Base<int> base(10);" << endl;

    cout << "typename和class作用一致，没有什么区别" << endl;
    cout << "作用范围 : 作用在最近的一对{}，在这一对{}中都可以使用。当括号结束，那么他的作用范围也结束了，例如：testFun就无法使用T" << endl;
    cout << "template没有类似于java的extend，但是编译器会自动帮我们推导。" << endl;
    cout << "也可以类似于func那样写，不会出现报错。但是当调用该方法是，确定类型必须含有func中内部的函数" << endl;
    cout << "例如：base去调用的时候就会出现错误，而base1去调用的时候就不会出现异常" << endl;
    cout << "-----------测试template函数模板 结束----------" << endl;
}

#endif //CBASE_TEMPLATETEST_H
