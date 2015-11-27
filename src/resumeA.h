#pragma once
#include "resume.h"

class ResumeA : public Resume
{
    public:
        ResumeA(const char* str);   //构造函数
        ResumeA(const ResumeA &r);  //拷贝构造函数
        ~ResumeA();     //析构函数
        ResumeA* Clone();       //克隆,关键所在
        void Show();    //显示内容
};
