//
// Created by zenghui on 1/4/21.
//
#include <iostream>
#include "CPlusBase1.h"


using namespace std;

/**
 * C++构造函数与析构函数
 * 什么是构造函数：
 * 构造函数是一种特殊的成员函数,与其他函数不同,不需要用户调用它,而是创建对象的时候自动调用。
 * 什么是析构函数：
 * 析构函数是对象不再使用的时候,需要清理资源的时候调用。C++编译器自动调用。
 */
class Parent {
public:
    int age;
    char *name = NULL;

    //无参构造
    Parent() {
        cout << "parent  调用无参构造函数" << endl;
    };

    //单参构造
    Parent(int age) {
        cout << "parent  调用单参构造函数" << endl;
        this->age = age;
    }

    //单参构造
    Parent(int age, char *name) {
        cout << "parent  调用单参构造函数" << endl;
        this->age = age;
        this->name = (char *) malloc(strlen(name) + 1);
        strcpy(this->name, name);
    }

    /**
     * explicit 关键字：
     * 被explicit关键字修饰的类构造函数，不能进行自动地隐式类型转换，只能显式地进行类型转换。
     * @param name
     */
    explicit Parent(char *name) {
        cout << "parent  调用多参构造函数" << endl;
        this->name = (char *) malloc(strlen(name) + 1);
        strcpy(this->name, name);
    }

    /**
     * 默认拷贝函数
     * @param parent 常量引用（防止原有值被修改）
     * 常量引用指向的内容不能修改，但是能重新赋值
     * 引用常量指向的内容能修改，但是不能修改
     * 注意：
     * 如果重写该方法必须对属性进行赋值，赋值会导致属性值为空
     *
     * 浅拷贝：
     * 所谓浅拷贝，指的是在对象复制时，只对对象中的数据成员进行简单的赋值，默认拷贝构造函数执行的
     * 也是浅拷贝。大多情况下“浅拷贝”已经能很好地工作了，但是一旦对象存在了动态成员，那么浅拷贝就
     * 会出问题了.
     *
     *
     * 深拷贝：
     *
     */
    Parent(const Parent &parent) {

        /**
         * 浅拷贝演示，当存在malloc的时候会出现报错。
         * 出现报错原因是由于浅拷贝是 将原有对象属性name的值赋值给新对象属性name。
         * 当新对象被释放时，name属性指向的堆中的数据被释放。
         * 而原有的对象属性name的指针还存在。
         * 当系统调用析构的时候释放原有对象时，由于name的指向被新对象释放掉了，系统调用的时候会再次去释放name对象从而二次释放的情况。出现报错
         */
//        this->age = parent.age;
//        this->name = parent.name;
//        this->height = parent.height;
        /**
         * 深拷贝：
         * 为了解决浅拷贝出现的问题.
         * 解决办法：
         * 重新对新对象开辟一个指向。释放的时候释放自己的，不在对原有对象的属性指向进行释放
         */

        cout << "parent  调用默认拷贝函数   深拷贝" << endl;
        this->age = parent.age;
        if (parent.name) {
            this->name = (char *) malloc(strlen(parent.name));
            strcpy(this->name, parent.name);
        }
        this->height = parent.height;
        cout << "parent  调用默认拷贝函数" << endl;
    }

    /**
     * 重写拷贝函数(存在风险，当里面对值进行修改，外面也会被修改)
     * java中使用的是这种
     * @param parent
     */
    Parent(Parent &parent) {
        /**
        * 对数据进行拷贝
        */
        this->age = parent.age;
        parent.age = 100;
        if (parent.name) {
            this->name = (char *) malloc(strlen(parent.name));
            strcpy(this->name, parent.name);
        }
        this->height = parent.height;
        cout << "parent  调用重写拷贝函数" << endl;
    }

    //析构函数
    ~Parent() {
        cout << "parent  调用析造函数" << endl;
        if (this->name != NULL) {
            free(this->name);
            this->name = NULL;
        }
    }

private:
    int height;
};

void testParent(Parent parent) {
    cout << "testParent  parent age:   " << parent.age << endl;
}

//void testParent(Parent &parent) {
//
//}

/**
 * 测试方法
 */
void testCPlus1() {
    /**
     * 1. 括号法创建实例
     */
    Parent p2(10);
    /**
     * Parent parent;
     * 对象已经在栈中创建
     * 并且能对该对象调用，或者赋值。
     */
    Parent parent;
    parent.age = 18;
    cout << "输出parent对象值：" << parent.age << endl;
    /**
     * 2. 隐式法创建，注意隐式调用无法调用多参构造（使用比较少，容易产生歧义）
     */
    Parent parent1 = 10;
    /**
     * explicit 修饰的构造方法无法用隐式的方法调用,只能使用显示的方法调用
     * 显示：
     * Parent parent2 = Parent(p);
     * 隐式：
     * Parent parent2 = p;
     */
    char a = 'a';
    char *p = &a;
//    Parent parent2 = p;
    Parent parent2 = Parent(p);

    /**
     * 3. 显示法创建实例
     */
    Parent p4 = Parent();
    /**
     * 4. 调用默认的拷贝函数
     */
    Parent parent3 = Parent(parent2);
    /**
     * 当数组创建时，对象会创建4个并且都会进行初始化
     */
    Parent pArr[4];

}

void testCPlus2() {
    cout << "创建案例结束，开始传参案例" << endl;
    /**
     * 输出：
     * parent  调用单参构造函数
     * parent  调用析造函数
     * parent  调用析造函数
     * 问题来了：
     * 为什么调用testParent(Parent p)会两次析构函数
     * void testParent(Parent p)
     * 当调用testParent(Parent p)方法是，C++会调用Parent默认的拷贝函数即：
     * Parent(const Parent &parent)
     * 对p进行初始化。即：
     * Parent p = Parent(const Parent &parent)。
     * 当存在重写的
     * Parent(Parent &parent)
     * 会调用重写的方法对p进行初始化。即：
     * Parent p = Parent(Parent &parent)。
     * 当testParent栈帧被销毁的时候，会调用P也就出现了开始只调用了一次构造函数却出现了两次析构函数的问题。
     *
     * 为什么调用testParent(Parent &p)只会析构函数
     * void testParent(Parent &p)由于采用的是引用的方法，引用指向的是原有的变量，不会重新创建一个新的变量。
     * 浅拷贝：
     * 所谓浅拷贝，指的是在对象复制时，只对对象中的数据成员进行简单的赋值，默认拷贝构造函数执行的
     * 也是浅拷贝。大多情况下“浅拷贝”已经能很好地工作了，但是一旦对象存在了动态成员，那么浅拷贝就
     * 会出问题了.比方说出现malloc
     * 深拷贝：
     *
     */
    Parent p5 = Parent(101, const_cast<char *>("zenghui"));
    testParent(p5);
    /**
     * 当重写了Parent(Parent &parent)，导致数据被修改
     */
    cout << "当重写了Parent(Parent &parent)，导致数据被修改 parent age：  " << p5.age << endl;
}




