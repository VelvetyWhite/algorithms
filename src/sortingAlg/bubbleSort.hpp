#ifndef _BUBBLE_SORT_
#define _BUBBLE_SORT_

#include <vector>
#include <utility>

void BubbleSort(std::vector<int>& v)
{
    int n = v.size();
    int newN;
    while(n > 0)
    {
        newN = 0;
        for(int i = 1; i < n; i++)
        {
            if(v[i - 1] > v[i])
            {
                std::swap(v[i - 1], v[i]);
                newN = i;
            }
        }
        n = newN;
    }
}

#endif
