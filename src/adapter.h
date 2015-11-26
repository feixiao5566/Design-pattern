#ifndef __ADAPTER_H__
#define __ADAPTER_H__

#include <iostream>
#include <string>

using namespace std;

//双端队列
class Deque
{
    public:
        void push_back(int x){cout<<"Deque push_back"<<endl;}
        void push_front(int x){cout<<"Deque push_front"<<endl;}
        void pop_back(){cout<<"Deque pop_back"<<endl;}
        void pop_front(){cout<<"Deque pop_front"<<endl;}
};
//顺序容器
class Sequence
{
    public:
        virtual void push(int x) = 0;
        virtual void pop() = 0;
};
//栈
class Stack : public Sequence       //意思是栈是顺序容器?
{
    public:
        void push(int x){deque.push_back(x);}   //所以如果有stack的对象就会打印这句,而非基类
        void pop(){deque.pop_back();}
    private:
        Deque deque;    //双端队列
};
//队列
class Queue : public Sequence
{
    public:
        void push(int x){deque.push_back(x);}
        void pop(){deque.pop_front();}
    private:
        Deque deque;    //双端队列
};


#endif
