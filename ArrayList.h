//
// Created by zenghui on 1/4/21.
//

#ifndef CBASE_ARRAYLIST_H
#define CBASE_ARRAYLIST_H

#include <iostream>

using namespace std;

class ArrayList {
private:
    int size = 16;
    int realSize = 0;
    int *arr;
public:
    /**
     * 重写拷贝函数，由于*arr是指针数组，多次释放会出现问题
     * @param arrayList
     */
    ArrayList(const ArrayList *arrayList);

    ArrayList();

    /**
     * explicit 关键字，避免外部隐式调用。造成歧义
     * @param size
     */
    explicit ArrayList(int size);

    void add(int val);

    void add(int index, int val);

    void remove(int index);

    int getValue(int index);

    bool isEmpty();

    void toString();

    void resetSize();

    virtual ~ArrayList();
};


#endif //CBASE_ARRAYLIST_H
