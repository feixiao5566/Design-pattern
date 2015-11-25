#ifndef __CACHE_H__
#define __CACHE_H__

#include <iostream>
#include <string>
#include "strategy.h"
//Cache需要用到的替换算法
enum RA {LRU, FIFO, RANDOM};    //标签
class Cache
{
    public:
        Cache(enum RA ra)
        {
            if(ra == LRU)
                m_ra = new LRU_ReplaceAlgorithm();
            else
//                if(ra == FIFO)
//                    m_ra = new FIFO_ReplaceAlgorithm();
//                else
                    if(ra == RANDOM)
                        m_ra = new Random_ReplaceAlgorithm();
                    else
                        m_ra = NULL;
        }
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
