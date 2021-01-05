//
// Created by zenghui on 1/4/21.
//

#include "ArrayList.h"

ArrayList::ArrayList(int size) : size(size) {
    this->size = size;
    this->realSize = 0;
    this->arr = new int[size];
}

ArrayList::ArrayList() {
    this->size = 16;
    this->realSize = 0;
    this->arr = new int[this->size];

}

ArrayList::~ArrayList() {
    if (this->arr) {
        delete[]this->arr;
        this->arr = NULL;
    }

}

void ArrayList::add(int val) {
    add(realSize, val);
}


void ArrayList::add(int index, int val) {
    if (index < 0 || index > size) {
        return;
    }
    if (index >= size * 0.75) {
        resetSize();
    }
    if (index == realSize) {
        arr[index] = val;
    } else {
        for (int i = realSize; i >= index; --i) {
            if (i != index) {
                arr[i] = arr[i - 1];
            } else {
                arr[i] = val;
            }
        }
    }
    realSize++;
}

void ArrayList::resetSize() {
    int newLenght = 2 * size;
    int *p = new int[newLenght];
    for (int i = 0; i < realSize; ++i) {
        *(p + i) = arr[i];
    }
    delete[]arr;
    arr = p;
    size = newLenght;
}

/**
 * 注意：此时无需释放。当对象释放是会调用析构函数对arr进行释放，如果此处释放将会导致多次释放的情况。
 * @param arrayList
 */
ArrayList::ArrayList(const ArrayList *arrayList) {
    size = arrayList->size;
    realSize = arrayList->realSize;
    arr = new int[size];
    for (int i = 0; i < arrayList->realSize; ++i) {
        arr[i] = arrayList->arr[i];
    }
}

int ArrayList::getValue(int index) {
    if (index < 0 || index > size || index > realSize) {
        return -1;
    }
    return arr[index];
}

void ArrayList::remove(int index) {
    int value = getValue(index);
    if (value == -1) {
        cout << "移除操作异常" << endl;
        return;
    }
    for (int i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    realSize--;
}

bool ArrayList::isEmpty() {
    return realSize == 0;
}

void ArrayList::toString() {
    cout << "[";
    for (int i = 0; i < realSize; ++i) {
        if (i == realSize - 1) {
            cout << arr[i];
        } else {
            cout << arr[i] << ",";
        }

    }
    cout << "]" << endl;
}
