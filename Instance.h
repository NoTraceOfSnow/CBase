//
// Created by zenghui on 1/5/21.
//

#ifndef CBASE_INSTANCE_H
#define CBASE_INSTANCE_H

/**
 * c++单例
 * 注意事项：
 * 必需保护拷贝构造函数，其他基本一致
 */
class Instance {

public:
    Instance *getInstacne() {
        return instance;
    }

    virtual ~Instance();

private:
    Instance *instance = new Instance();

    /**
     * 保护构造函数
     */
    Instance();

    /**
     * 单例模式必需保护构造拷贝函数
     */
    Instance(const Instance &instance) {

    }

};


#endif //CBASE_INSTANCE_H
