#include "factory.h"
//主函数测试简单工厂
 int main()
{
    Factory* factory = new Factory();
    factory->CreateSingleCore(COREA)->Show();
    factory->CreateSingleCore(COREB)->Show();

    return 0;
}
