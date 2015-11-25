#include "strategy.h"
#include "cache.h"

int main()
{
    Cache cache(new LRU_ReplaceAlgorithm());    //暴露了算法的定义
    cache.Replace();
    return 0;
}
