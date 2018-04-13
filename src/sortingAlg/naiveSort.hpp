#ifndef _NAIVE_SORT_
#define _NAIVE_SORT_

#include <vector>
#include <utility>

void NaiveSort(std::vector<int>& v)
{
    for(int i = 0; i < v.size() - 1; i++)
    {
        for(int j = i + 1; j < v.size(); j++)
        {
            if(v[j] < v[i])
            {
                std::swap(v[j], v[i]);
            }
        }
    }
}

#endif
