#include "adapter.h"

int main()
{
    Sequence *s1 = new Stack();     //在stack的私有成员中有初始化deque对象
    Sequence *s2 = new Queue();     //类继承,返回值类型和new类型
    s1->push(1);
    s1->pop();
    s2->push(1);
    s2->pop();
    delete s1;      //delete和new是C++保留关键字,不需要头文件
    delete s2;
    return 0;
}
//以上是对象适配器.
//STL实现了一种数据结构,双端队列deque,支持前后两段的插入和删除
//借用栈的后端插入后端删除和队列的前端插入前端删除实现

