#include <random>
#include <iostream>

#include "mergeSort.hpp"
#include "quickSort.hpp"

#define VEC_SIZE 15

template<class T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
    os << "[";
    for(auto val : v)
    {
        os << " " << val;
    }
    os << "]";
    return os;
}

int main()
{
    std::random_device randDevice;
    std::uniform_int_distribution<int> randDistribution(-200000, +800000);
    std::mt19937 randEngine(randDevice());

    std::vector<int> randVec;
    for(int i = 0; i < VEC_SIZE; i++)
    {
        randVec.push_back(randDistribution(randEngine));
    }
    std::vector<int> testVec = randVec;

    std::cout << testVec << "\n";
    MergeSort(testVec, 0, testVec.size() - 1);
    std::cout << "After MergeSort: \n" << testVec << "\n";

    testVec = randVec;
    MergeSortIter(testVec);
    std::cout << "After MergeSortIter: \n" << testVec << "\n";

    testVec = randVec;
    QuickSort(testVec, 0, testVec.size() - 1);
    std::cout << "After QuickSort: \n" << testVec << "\n";

    testVec = randVec;
    QuickSortIter(testVec, 0, testVec.size() - 1);
    std::cout << "After QuickSortIter: \n" << testVec << "\n";

    return 0;
}
