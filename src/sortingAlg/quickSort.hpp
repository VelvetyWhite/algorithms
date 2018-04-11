#ifndef _QUICK_SORT_
#define _QUICK_SORT_

#include <vector>
#include <stack>
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

void QuickSortIter(std::vector<int>& v, int startIndex, int endIndex)
{
    std::stack<int> auxStack;
    
    auxStack.push(startIndex);
    auxStack.push(endIndex);

    while(!auxStack.empty())
    {
        endIndex = auxStack.top();
        auxStack.pop();
        startIndex = auxStack.top();
        auxStack.pop();

        int partitionIndex = Partition(v, startIndex, endIndex);

        if(partitionIndex - 1 > startIndex)
        {
            auxStack.push(startIndex);
            auxStack.push(partitionIndex - 1);
        }
        if(partitionIndex + 1 < endIndex)
        {
            auxStack.push(partitionIndex + 1);
            auxStack.push(endIndex);
        }
    }
}

#endif
