#pragma once
#include "resume.h"

class ResumeB : public Resume
{
    public:
        ResumeB(const char* str);   //构造函数
        ResumeB(const ResumeB &r);  //拷贝构造函数
        ~ResumeB();     //析构函数
        ResumeB* Clone();       //克隆,关键所在
        void Show();    //显示内容
};
