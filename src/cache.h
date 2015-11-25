#ifndef __CACHE_H__
#define __CACHE_H__

#include <iostream>
#include "strategy.h"
class Cache
{
    public:
        Cache(ReplaceAlgorithm *ra) : m_ra(ra)
        {}
        ~Cache()
        {
            delete m_ra;
        }
        void Replace()
        {
            m_ra->Replace();
        }
    private:
        ReplaceAlgorithm *m_ra;
};
#endif
