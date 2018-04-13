#ifndef _INSERTION_SORT_
#define _INSERTION_SORT_

#include <vector>

void InsertionSort(std::vector<int>&v)
{
    int elementToInsert;
    int insertionPosition;
    for(int i = 1; i < v.size(); i++)
    {
        elementToInsert = v[i];
        insertionPosition = i;
        while(insertionPosition > 0 && v[insertionPosition - 1] > elementToInsert)
        {
            v[insertionPosition] = v[insertionPosition - 1];
            insertionPosition--;
        }
        v[insertionPosition] = elementToInsert;
    }
}

#endif
