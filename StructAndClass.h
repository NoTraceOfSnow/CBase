//
// Created by zenghui on 1/5/21.
//

#ifndef CBASE_STRUCTANDCLASS_H
#define CBASE_STRUCTANDCLASS_H
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
     *  C++会默认建立一个数组指针存放virtual函数，用于子类继承
     *
     */
    virtual void test();
};


#endif //CBASE_STRUCTANDCLASS_H
