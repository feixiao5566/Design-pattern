#include "strategy.h"
#include "cache.h"

int main()
{
    Cache<Random_ReplaceAlgorithm> cache;   //模板实参
    cache.Replace();
    return 0;
}
