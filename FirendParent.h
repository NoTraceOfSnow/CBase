//
// Created by zenghui on 1/5/21.
//

#ifndef CBASE_FRIENDPARENT_H
#define CBASE_FRIENDPARENT_H

#include "FrendTest.h"
#include "FirendTest2.h"

class FriendParent {
    friend class FrendTest;

    friend void FirendTest2::test2();

public:
    int age = 0;
    FriendParent() {

    }

private:
    char *name = "红色";

    void friendFunc() {

    }

};


#endif //CBASE_FRIENDPARENT_H
