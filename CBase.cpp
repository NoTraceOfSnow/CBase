#include <iostream>
#include "CPlusBase.h"
#include "CPlusBase1.h"
#include "ArrayList.h"
#include "StructAndClass.h"
#include "FrendTest.h"

using namespace std;

int intFunAdd(int a, int b) {
    printf("intFun %d  %d \n", a, b);
    return a + b;
}


int intFunCut(int a, int b) {
    printf("intFun %d  %d \n", a, b);
    return a - b;
}

void voidFun(int a, int b) {
    printf("voidFun %d \n", a + b);
}


void myStrCat(char *s1, char *s2) {
    while (*s1) {
        printf("myStrCat s1 %c \n", *s1);
        s1++;
    }
    printf("myStrCat s1 end %c \n", *s1);
    while (*s2) {
        *s1 = *s2;
        printf("myStrCat s2 end %c \n", *s1);
        s1++;
        s2++;
    }
}


int main() {

    int *nuInitP;
    /**
     * 未初始化指针是有一个虚地址的
     */
    printf("nuInitP   %p \n", &nuInitP);
    /**
     * 当对一个虚地址进行赋值时，就会抛出异常。原因是什么：
     * 当定义一个指针，内存会给该指针设置一个虚拟地址。该指针能取到地址，但是没有真正的指向位置。
     * 当我们对其赋值时，一个没有初始化的指针由于没有真正的指向位置。就会出现异常，即我们常说的野指针
     *
     */
//    *nuInitP = 8;
    /**
     * 数组指针,大小为8
     * int (*parr1)[5];
     * int 表示数组指向的是int值，对p[0]取值返回int
     * 指针数组，大小为步长，即40
     * int *parr2[5];
     * int 表示指针数组中的指针返回值是int，对p[0]取值返回值是指针，对返回值指针取值返回值是int
     */
    /**
     * 二维数组
     */
    int (*parr1)[5];
    cout << "数组指针大小 ： " << sizeof(parr1) << endl;
    int *parr2[5];
    cout << "指针数组大小 ： " << sizeof(parr2) << endl;
    char a[2][3] = {
            'z', 'd', 'l',
            'v', 'n', 'e'
    };
    char (*parr)[3] = a;
    /**
     * 为什么&a  a  parr的地址是一样的？
     * a变量我们都知道是二维数组
     * a的地址和&a的地址一致毋庸置疑。都是第一个元素的地址
     * 那么为什么parr的地址和a的地址是一致的？parr又指向哪里?
     * parr是一个长度为3的数组指针，它指向a的第一行数据的第一个元素，即
     * 'z', 'd', 'l'
     * 所以parr的地址与a，&a，以及数组的第一个元素的地址一致。
     */
    printf("a数组第一个元素的地址：   %p\n", &a[0][0]);
    printf("&a的地址：  %p\n", &a);
    printf("a的地址：   %p\n", a);
    printf("a的值：   %c\n", a[0][0]);
    printf("arrp的地址：   %p\n", parr);
    printf("arrp的大小：   %lu\n", sizeof(parr));
    printf("a的地址：   %p\n", a + 1);

    /**
     * 对二维数组进行取值
     * 1.下标法
     * 2.指针法
     */
    //下标法
    printf("下标取值：  %c\n", a[0][1]);
    //指针法
    char (*p)[3] = a + 1; //数组指针
    printf("p的地址：   %p\n", p);

    int (*funint)(int, int) =intFunCut;

    printf("funint %d \n", funint(20, 80));

    void (*funVoid)(int, int) =voidFun;

    funVoid(20, 80);

    /**
     * 函数指针数组  用于实现观察者模式(数组中存放回调，当有数据改变，对所有的函数进行调用)
     * 提问：什么是函数指针，即返回值为指针的函数。
     * 函数指针与指针函数的区别
     * 函数指针是指一个指向函数的指针变量
     * 指针函数是指返回值为指针的函数
     */

    int (*funArr[2])(int a, int b) ={intFunAdd, intFunCut};
    printf("---   sizeof funArr  %lu  \n", sizeof(funArr) / 8);
    /**
     * 注意此处用sizeof取值会出现问题，sizeof计算的是指向类型，此处指向类型是函数指针数组，且数组长度是2.
     * 返回值是16与我们预期的2是不一致的，所以我们除以指针的长度以获得正确的值
     */
    for (int i = 0; i < sizeof(funArr) / 8; ++i) {
        printf("---   funArr  %d  \n", funArr[i](20, 90));
    }

//    char k[3] = {'a', 'b', 'c'};
//    /**
//     * 由于arrCharP是数组指针，赋值给 数组指针(举例)
//     */
//    char (*arrCharP)[3] = &k;
    /**
     * 这种属于常量指针
     * 它不能指向变量，它指向的内容不能被改变，不能通过指针修改它的值。但是它自身不是一个常量，他自身可以改变，从而指向一个常量
     * 简单的说    不能修改其指向的内容   能重新赋值
     * char *startStr="123";
     * char *endStr="456";
     * c++11写法
     * const char *startStr="123";
     * 这种属于指针常量
     * 它指向的地址不能改变，但是地址里面的值能通过指针进行修改。它的地址将伴其一生，直到生命周期结束。需要注意的一点是定义是必须同时赋值。
     * 简单的说    能修改其指向的内容   不能重新赋值
     * char startStr[] = "abc";
     */
    char startStr[] = "abc";
    char endStr[] = "456";

    myStrCat(startStr, endStr);

    printf("myStrCat end %s \n", startStr);
    printf("myStrCat end %d \n", static_cast<int>(strlen(startStr)));
    /**
     * arrStr是 常量指针数组
     * 后面的指针是指向的常量（在堆区）
     */
    const char *arrStr[4] = {"aaa", "bbb", "ccc", "ddd"};

    arrStr[0] = "ABC";
    printf("arrStr %s \n", arrStr[0]);
    /**
     * arrStr2[0]无法赋值原因
     * 1.我们要知道arrStr2中的存放的是什么
     * const char *arrStr2[4][6] = {"aaa", "bbb", "ccc", "ddd"};
     * 等同于
     * char arr1[]="aaa";
     * char arr2[]="bbb";
     * char arr3[]="ccc";
     * char arr4[]="ddd";
     * const char *arrStr2[4][6] = {arr1,arr2,arr3,arr4};
     * 由于arrStr2是存放的是指针常量，所以无法对其进行赋值。
     */
    const char *arrStr2[4][6] = {"aaa", "bbb", "ccc", "ddd"};
    //arrStr2[0]="aaa";


    //----------------- 结构体 ---------------------
    /**
     * 从表面上看Node的大小应该为5
     * 但是输出Node结构体的大小却是8
     * 原因：由于内存对齐的原因，结构体大小是最大基础类型的整数倍
     * Node中的char内存对齐后大小就变为了4，所以Node输出的结构体大小为8
     * Node1中的char内存对齐后大小就变为了8，所以Node1输出的结构体大小为16
     * Node2中的Node1结构体大小为16，但是Node1内部的最大基本类型为double即8字节，
     * 所以Node2中char内存对齐后大小为8，最终Node2结构体整体大小为24.
     */
    struct Node {
        char a;
        int b;
    } node;

    struct Node1 {
        char a;
        double b;
    } node1;

    struct Node2 {
        Node1 node;
        char a;
    } node2;

    printf("结构体Node的大小  %lu \n", sizeof(node));
    printf("结构体Node的大小  %lu \n", sizeof(node1));
    printf("结构体Node的大小  %lu \n", sizeof(node2));
    /**
     * 复杂函数如何阅读：
     * 采用右左法则进行解析：
     * 首先找到未定义的标识符pfun，当往右看的时候遇到括号，于是调转方向，再往反方向看。
     * 1.pfun遇到了*，说明pfun是一个指针。
     * 继续往左看的时候遇到括号，于是调转方向
     * 2.遇到的是另一个括号，因此说明该指针是一个函数指针
     * 函数的参数是一个int *（整型指针）
     * 3.然后又向反方向查看，遇到*，说明该函数指针的返回值是指针
     * 继续往左看遇到括号，调转方向把括号里面的内容看完，出了括号就是数组
     * 说明指针所指向的函数的返回值类型的指针指向的是数组
     * 简单的说：
     * pfun就是一个函数指针，
     */
    int *(*(*pfun(int *)))[10];
    /**
     * 阅读举例:
     * 首先找到那个未定义的标识符，就是func，
     * 它的外面有一对圆括号，而且左边是一个*号，这说明func是一个指针，
     * 然后跳出这个圆括号，先看右边，也是一个圆括号，这说明(*func)是一个函数，
     * 而func是一个指向这类函数的指针，就是一个函数指针，
     * 这类函数具有int*类型的形参，返回值类型是 int。
     */
    int (*func)(int a, int b) =intFunCut;

    /**
     * func被一对括号包含，且左边有一个*号，说明func是一个指针，
     * 跳出括号，右边也有个括号，那么func是一个指向函数的指针，
     * 这类函数具有int *和int (*)(int*)这样的形参，返回值为int类型。
     * 再来看一看func的形参int (*f)(int*)，类似前面的解释，f也是一个函数指针，
     * 指向的函数具有int*类型的形参，返回值为int。
     */
    //复杂  规则 本质
    int (*func1)(int *p, int (*f)(int *));


    /**
     * func右边是一个[]运算符，说明func是一个具有5个元素的数组，
     * func的左边有一个*，说明func的元素是指针，要注意这里的*不是修饰 func的，
     * 而是修饰func[5]的，原因是[]运算符优先级比*高，func先跟[]结合，
     * 因此*修饰的是func[5]。跳出这个括号，看右边，也是一对圆括号，
     * 说明func数组的元素是函数类型的指针，它所指向的函数具有int*类型的形参，
     * 返回值类型为int。
     */
    //    func2  本质 数组1     指针 2

    int (*func2[5])(int *pInt);

    //func3   数组1   指针2
    /**
     * func被一个圆括号包含，左边又有一个*，
     * 那么func是一个指针，跳出括号，
     * 右边是一个[]运算符号，说明func是一个指向数组的指针，
     *  现在往左看，左边有一个*号，说明这个数组的元素是指针，
     */
    int (*(*func3)[5])(int *pInt);

    //输入  int * 地址变量  输出   int (*result)[5]
    int (*(*func4)(int *pInt))[5];
    /**
     * func是一个返回值为具有5个int元素的数组的函数。
     * 但C语言的函数返回值不能为数组，这是因为如果允许函数返回值为数组，
     * 那么接收这个数组的内容的东西，也必须是一个数组，但C语言的数组名是一个右值，
     * 它不能作为左值来接收另一个数组，
     * 因此函数返回值不能为数组。
     */
    //    int func8(void)[5];//非法
    /**
     * func是一个具有5个元素的数组，这个数组的元素都是函数。
     * 这也是非法的，因为数组的元素除了类型必须一样外，
     * 每个元素所占用的内存空间也必须相同，显然函数是无法达到这个要求的，
     * 即使函数的类型一样，但函数所占用的空间通常是不相同的。
     */
    //    int func9[5](void)
    int func10(void);

    //------------------- c++ -------------------
    auto plus = new CPlusBase();
    delete (plus);

    testCPlus1();

    testCPlus2();

    cout << "测试自定义数组" << endl;
    ArrayList arrayList = new ArrayList;
    arrayList.add(1);
    arrayList.add(2);
    arrayList.add(3);
    arrayList.add(4);
    arrayList.add(2, 8);
    arrayList.toString();
    cout << "测试自定义数组结束" << endl;

    cout << "单例必需保护拷贝构造函数" << endl;

    cout << "空struct大小" << sizeof(StructSize) << endl;
    cout << "空Class大小" << sizeof(StructAndClass) << endl;

    cout << "带参struct大小" << sizeof(StructSize1) << endl;
    cout << "带参Class大小" << sizeof(StructAndClass1) << endl;

    cout << "无参有virtual方法的Class大小" << sizeof(StructAndClass2) << endl;
    cout << "------------------" << endl;
    cout << "struct与class总结：" << endl;
    cout << "当没有任何参数的时候，大小均为1，当有参数的时候，不管什么修饰符下，大小为最大参数的整数倍,类似于StructAndClass1" << endl;
    cout << "并且class当拥有virtual修饰的虚函数或者纯虚函数是，大小8" << endl;
    cout << "------------------" << endl;

    FrendTest friendTest;
    friendTest.test();
    return 0;
}


/**
 * 此时返回temp引用会出现异常，temp在函数fn1执行完后已经被回收了
 * 那么返回的引用就是一个无效引用，需要将temp定义成全局的
 * @param value
 * @return
 */

float temp;

float &fn1(float &value) {
//    float temp = value * 3;
    temp = value * 3;
    return temp;
}