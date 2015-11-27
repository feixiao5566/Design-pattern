#include "resume.h"
#include "resumeB.h"
#include <string.h>
#include <iostream>

ResumeB::ResumeB(const char *str)
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
ResumeB::~ResumeB() {delete [] name;}
ResumeB::ResumeB(const ResumeB &r)
{
    name = new char[strlen(r.name)+1];
    strcpy(name, r.name);
}
ResumeB* ResumeB::Clone()
{
    return new ResumeB(*this);
}
void ResumeB::Show()
{
    std::cout<<"ResumeB name: "<<name<<std::endl;
}
