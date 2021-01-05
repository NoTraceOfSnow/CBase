//
// Created by zenghui on 1/5/21.
//

#ifndef CBASE_BOX_H
#define CBASE_BOX_H

#include <iostream>

using namespace std;

class Box {
public:

    double getVolume(void) {
        return length * breadth * height;
    }

    void setLength(double len) {
        length = len;
    }

    void setBreadth(double bre) {
        breadth = bre;
    }

    void setHeight(double hei) {
        height = hei;
    }

    // 重载 + 运算符，用于把两个 Box 对象相加
    Box operator+(const Box &b) {
        Box box;
        box.length = this->length + b.length;
        box.breadth = this->breadth + b.breadth;
        box.height = this->height + b.height;
        return box;
    }

    Box operator*(const Box &b) {
        Box box;
        box.length = this->length * b.length;
        box.breadth = this->breadth * b.breadth;
        box.height = this->height * b.height;
        return box;
    }

private:
    double length;      // 长度
    double breadth;     // 宽度
    double height;      // 高度
};

// 程序的主函数
int boxText() {
    Box box1;                // 声明 Box1，类型为 Box
    Box box2;                // 声明 Box2，类型为 Box
    // 声明 Box3，类型为 Box
    double volume = 0.0;     // 把体积存储在该变量中

    // Box1 详述
    box1.setLength(6.0);
    box1.setBreadth(7.0);
    box1.setHeight(5.0);

    // Box2 详述
    box2.setLength(12.0);
    box2.setBreadth(13.0);
    box2.setHeight(10.0);

    // Box1 的体积
    volume = box1.getVolume();
    cout << "Volume of Box1 : " << volume << endl;

    // Box2 的体积
    volume = box2.getVolume();
    cout << "Volume of Box2 : " << volume << endl;

    // 把两个对象相加，得到 Box3
    Box box3 = box1 + box2;
    cout << "运算 box1 + box2 : " << box3.getVolume() << endl;

    Box box4 = box1 * box2;
    cout << "运算 box1 * box2 : " << box4.getVolume() << endl;
    return 0;
}


#endif //CBASE_BOX_H
