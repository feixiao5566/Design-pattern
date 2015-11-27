#include "resume.h"
#include "resumeA.h"
#include <iostream>
#include <string.h>

ResumeA::ResumeA(const char *str)
{
    if(NULL == str)
    {
        name = new char[1];
        name[0] = '\0';
    }
    else
    {
        name = new char[strlen(str)+1];
        strcpy(name, str);
    }
}
ResumeA::~ResumeA() {delete [] name;}
ResumeA::ResumeA(const ResumeA &r)
{
    name = new char[strlen(r.name)+1];
    strcpy(name, r.name);
}
ResumeA* ResumeA::Clone()
{
    return new ResumeA(*this);
}
void ResumeA::Show()
{
    std::cout<<"ResumeA name: "<<name<<std::endl;
}
