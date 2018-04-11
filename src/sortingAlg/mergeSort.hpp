#ifndef _MERGE_SORT_
#define _MERGE_SORT_

#include <vector>
#include <algorithm>

static void Merge(std::vector<int>& v, int leftIndex, int middleIndex, int rightIndex)
{
    const int size_1 = middleIndex - leftIndex + 1;
    const int size_2 = rightIndex - middleIndex;

    std::vector<int> left(size_1);
    std::vector<int> right(size_2);

    for(int i = 0; i < size_1; i++)
    {
        left[i] = v[leftIndex + i];
    }
    for(int i = 0; i < size_2; i++)
    {
        right[i] = v[middleIndex + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = leftIndex;
    while(i < size_1 && j < size_2)
    {
        if(left[i] <= right[j])
        {
            v[k] = left[i];
            i++;
        }
        else
        {
            v[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < size_1)
    {
        v[k] = left[i];
        i++;
        k++;
    }
    while(j < size_2)
    {
        v[k] = right[j];
        j++;
        k++;
    }
}

void MergeSort(std::vector<int>& v, int leftIndex, int rightIndex)
{
    if((leftIndex < rightIndex) && (rightIndex <= v.size()))
    {
        //avoid overflow of (leftIndex + rightIndex) / 2 for large index values
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
        MergeSort(v, leftIndex, middleIndex);
        MergeSort(v, middleIndex + 1, rightIndex);

        Merge(v, leftIndex, middleIndex, rightIndex);
    }
}

void MergeSortIter(std::vector<int>& v)
{
    for(int currentSize = 1; currentSize <= v.size() - 1; currentSize *= 2)
    {
        for(int leftStart = 0; leftStart < v.size() - 1; leftStart += 2 * currentSize)
        {
            //ending point of left subarray
            int mid = leftStart + currentSize - 1;
            int rightEnd = std::min((leftStart + 2 * currentSize - 1), int(v.size() - 1));

            Merge(v, leftStart, mid, rightEnd);
        }
    }
}

#endif
