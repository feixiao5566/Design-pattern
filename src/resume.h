#pragma once
#include <iostream>
//首先抽象一个基类
class Resume
{
    protected:
        char *name;
    public:
        Resume()    {}
        virtual ~Resume()   {}
        virtual Resume* Clone() {return NULL;}
        virtual void Set (char *n)  {}
        virtual void Show() {}
};
