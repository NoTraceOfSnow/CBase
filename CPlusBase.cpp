//
// Created by zenghui on 12/30/20.
//
#include <iostream>
#include "CPlusBase.h"

using namespace std;

/**
 * 宏定义
 * @return
 */
#define  funFine(a, b) a+b
#define  funFine1(a, b)(a+b)

/**
 * 内联函数
 */
inline int funFineInline(int a, int b) {
    return a + b;
}

void swap1(int &a, int &b);

/**
 * 方法重载
 * @param a
 */
void funOverLoading(int a);

/**
 * 方法重载
 * @param a
 */
void funOverLoading(int &a);

/**
 * 方法重载
 * @param a
 */
void funOverLoading(int *a);

/**
 * 方法重载
 * @param a
 */
void funOverLoading(const int *a);

CPlusBase::CPlusBase() {
    cout << "调用C++" << endl;
    //cout 输出
    cout << "aaa" << "bbb" << endl;

    int y = 20, k = 30;
    cout << "引用交换测试原始值  " << y << " ----" << k << endl;
    /**
     * 引用 &y1 此时不是取址操作，而是引用，引用不会分配内存，可以节省内存。但初始化必须赋值
     * 当对引用进行修改，那么引用的变量值也会随之修改
     * 例如：
     * y1==100
     * y也就等于100
     * 当有const修饰时，就相当于常量指针：
     * const int &y1 = y;
     * y1=100 //此时编译器会报错，无法对其进行赋值。
     *
     * 当返回值是引用的时候，需要注意指向对象是否被回收。如被回收将会出现异常。
     * 例如：函数 fn1 调用完后temp被回收了，导致返回的引用出现问题，此时需要将temp定义为全局变量避免被回收出现异常。
     * 并且需要注意，
     * 引用不能返回局部函数返回的堆中变量，会导致内存泄漏无法回收问题。
     * 引用不能引用局部变量
     */
    int &y1 = y;
    //使用引用替换y和k的值
    swap1(y, k);
    cout << "引用交换 y和k的值" << y << " ----" << k << endl;

    /**
     * 宏定义与内联函数的区别
     * 1.宏是有预处理器对宏进行替换，而内联函数是有编译器来控制的。
     * 2.内联函数是真正的函数，只是在需要用到的时候，内联函数像宏一样展开，
     * 所以取消了函数的参数压栈，减少了调用的开销。可以像函数一样调用，不用担心类似于调用宏的问题。例如，括号问题导致结果不一致：
     * 调用宏 funFine(10,20)*30
     * 返回结果是 610
     * 调用宏 funFine1(10,20)*30
     * 返回结果是 900
     * 3.内联函数与带参宏定义进行比较，他们的执行效率是一致的。但是内联函数要由于宏定义，
     * 因为内联函数遵循的类型和作用域规则，和一般函数更接近。
     * 4.在一些编译中，一旦关联上的内联扩展，将于一般函数一样进行调用，比较方便。
     *
     * 内联函数注意点以及缺点：
     * 1.不能使用switch
     * 2.不能存在过多的判断语句
     * 3.函数体不能过于庞大
     * 4.不能对函数进行取址操作
     * 5.inline对于编译器来说是一种建议，编译器可以忽略这种建议。
     * 当内联函数出现注意点情况时，编译器会忽略inline建议，还原成普通函数。
     */
    int fvalue = funFine(10, 20) * 30;
    cout << "宏定义不带括号   " << fvalue << endl;

    int fvalue1 = funFine1(10, 20) * 30;
    cout << "宏定义带括号   " << fvalue1 << endl;

    int inlineValue = funFineInline(10, 20) * 30;
    cout << "inline函数   " << inlineValue << endl;

    /**
     * 占位函数
     * 什么是占位函数：
     * 例如：
     * placeholderFun  函数
     * 其中int =0无法对该参数进行取值。
     *
     * C++支持这样的函数占位参数有什么意义？
     * 1.为以后程序扩展留下线索
     * 2.兼容c语言程序中可能出现的不规范写法
     */
    placeholderFun(10, 20, 30);

    /**
     * funOverLoading(10);
     * int a = 10;
     * int &b = a;
     * funOverLoading(b);
     * funOverLoading(int & a)和funOverLoading(int a)
     * 不算做方法重载，由于调用的时候存在二义性，且int &a 与int a都为变量，调用时存在报错，不算做方法重载。
     *
     * funOverLoading(int a,int b=10)和funOverLoading(int a)
     * 不算做方法重载，虽然定义是不存在报错，调用的时候存在二义性。
     * 如果硬是要调用如何解决：
     * typedef void (*funA)(int a,int b);
     * typedef void (*funA2)(int a);
     * 采用函数指针的方式调用。
     *
     * 总结：C++中函数参数长度不一致，不一定是重载。
     *
     * funOverLoading(int & a)和funOverLoading(int *a)
     * 算作方法重载，引用和指针不冲突。
     *
     * funOverLoading(int &a)和funOverLoading(const int& a)
     * 引用与常量引用也算作重载，由于int &a是一个变量，const int &a是指向的是一个常量，所以认为是方法重载。
     *
     * funOverLoading(int *a)和funOverLoading(const int *a)
     * 指针与常量指针也算作重载，由于int *a是一个变量，const int *a是指向的是一个常量，所以认为是方法重载。
     *
     * funOverLoading(int *a)和funOverLoading(int * const a)
     * 指针与指针常量不算作重载，由于int *a是一个变量， int *a const也是指向的一个变量，所以不是方法重载。
     *
     * 回顾指针常量与常量指针
     * 指针常量：无法重新赋值 内容是变量可以进行修改
     * 常量指针：能够重新赋值 内容是常量无法修改
     *
     */

}


void swap1(int &a, int &b) {
    int i = a;//此处的i是指向的int变量，而并非指向的引用，因为引用本身没有分配内存
    a = b;
    b = i;
}

/**
 * 占位函数，第三个参数无法获取
 *
 * @param a
 * @param b
 */
void CPlusBase::placeholderFun(int a, int b, int) {
    cout << "占位函数   " << a << "  -----  " << b << endl;
}


CPlusBase::~CPlusBase() {
    cout << "调用析构" << endl;
}
