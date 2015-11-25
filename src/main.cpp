#include "strategy.h"
#include "cache.h"

int main()
{
    Cache<Random_ReplaceAlgorithm> cache;   //模板实参
    cache.Replace();
    return 0;
}
//利用模板实现. 算法通过模板的实参指定.
//虽然还是使用了参数, 只不过不是构造函数的参数.
//在策略模式中, 参数的传递难以避免,客户必须指定某种算法
