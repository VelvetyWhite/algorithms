#ifndef _SELECTION_SORT_
#define _SELECTION_SORT_

#include <vector>
#include <utility>

void SelectionSort(std::vector<int>& v)
{
    int minIndex;
    for(int i = 0; i < v.size() - 1; i++)
    {
        minIndex = i;
        for(int j = i + 1; j < v.size(); j++)
        {
            if(v[j] < v[minIndex])
            {
                minIndex = j;
            }
        }
        if(minIndex != i)
        {
            std::swap(v[minIndex], v[i]);
        }
    }
}

#endif
