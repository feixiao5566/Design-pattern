#include <string.h>
#include "singleton.h"
#include "singletonA.h"
#include "singletonB.h"

Singleton* Singleton::singleton = NULL;
Singleton* Singleton::GetInstance(const char* name)     //这个函数调用之后实例化一个类对象
{
    if(NULL == singleton)
    {
        if(0 == strcmp(name, "SingletonA"))
            singleton = new Singleton();
        else
            if(0 == strcmp(name, "SingletonB"))
                singleton = new SingletonB();
            else
                singleton = new Singleton();
    }
    return singleton;
}
