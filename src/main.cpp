#include "singleton.h"
int main()
{
    Singleton *st = Singleton::GetInstance("SingletonA");
    st->Show();
    return 0;
}
