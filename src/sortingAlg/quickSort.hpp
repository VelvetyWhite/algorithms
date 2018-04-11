#ifndef _QUICK_SORT_
#define _QUICK_SORT_

#include <vector>
#include <utility>

static int Partition(std::vector<int>& v, int startIndex, int endIndex)
{
    int pivot = v[endIndex];
    int smallerIndex = startIndex;

    for(int j = startIndex; j <= endIndex - 1; j++)
    {
        if(v[j] <= pivot)
        {
            std::swap(v[smallerIndex], v[j]);
            smallerIndex++;
        }
    }
    std::swap(v[smallerIndex], v[endIndex]);
    return smallerIndex;
}

void QuickSort(std::vector<int>& v, int startIndex, int endIndex)
{
    if(startIndex < endIndex)
    {
        //element at right position
        int partitionIndex = Partition(v, startIndex, endIndex);
        
        //sort before and after partition
        QuickSort(v, startIndex, partitionIndex - 1);
        QuickSort(v, partitionIndex + 1, endIndex);
    }
}

#endif
