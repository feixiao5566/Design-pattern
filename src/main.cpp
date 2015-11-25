#include "strategy.h"
#include "cache.h"

int main()
{
    Cache cache(LRU);    //指定标签即可
    cache.Replace();
    return 0;
}

//相比方法一,这种方式简单多
//这两种方式是将简单工厂模式与策略模式结合在一起,算法的定义使用了策略模式,
//而Cache的定义其实使用了简单工厂模式
