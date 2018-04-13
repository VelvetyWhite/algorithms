#include <random>
#include <iostream>
#include <chrono>

#include "mergeSort.hpp"
#include "quickSort.hpp"
#include "insertionSort.hpp"
#include "selectionSort.hpp"
#include "naiveSort.hpp"
#include "bubbleSort.hpp"

#define VEC_SIZE 10000

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

//    std::cout << testVec << "\n";
    auto t1 = std::chrono::high_resolution_clock::now();
    MergeSort(testVec, 0, testVec.size() - 1);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto t = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    std::cout << "MergeSort duration: " << t << "\n";

#ifdef PRINT_SORTED
    std::cout << "After MergeSort: \n" << testVec << "\n";
#endif

    testVec = randVec;
    t1 = std::chrono::high_resolution_clock::now();
    MergeSortIter(testVec);
    t2 = std::chrono::high_resolution_clock::now();
    t = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    std::cout << "Iterative MergeSort duration: " << t << "\n";

#ifdef PRINT_SORTED
    std::cout << "After MergeSortIter: \n" << testVec << "\n";
#endif

    testVec = randVec;
    t1 = std::chrono::high_resolution_clock::now();
    QuickSort(testVec, 0, testVec.size() - 1);
    t2 = std::chrono::high_resolution_clock::now();
    t = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    std::cout << "QuickSort duration: " << t << "\n";

#ifdef PRINT_SORTED
    std::cout << "After QuickSort: \n" << testVec << "\n";
#endif

    testVec = randVec;
    t1 = std::chrono::high_resolution_clock::now();
    QuickSortIter(testVec, 0, testVec.size() - 1);
    t2 = std::chrono::high_resolution_clock::now();
    t = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    std::cout << "Iterative QuickSort duration: " << t << "\n";

#ifdef PRINT_SORTED
    std::cout << "After QuickSortIter: \n" << testVec << "\n";
#endif

    testVec = randVec;
    t1 = std::chrono::high_resolution_clock::now();
    InsertionSort(testVec);
    t2 = std::chrono::high_resolution_clock::now();
    t = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    std::cout << "InsertionSort duration: " << t << "\n";

#ifdef PRINT_SORTED
    std::cout << "After InsertionSort: \n" << testVec << "\n";
#endif

    testVec = randVec;
    t1 = std::chrono::high_resolution_clock::now();
    SelectionSort(testVec);
    t2 = std::chrono::high_resolution_clock::now();
    t = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    std::cout << "SelectionSort duration: " << t << "\n";

#ifdef PRINT_SORTED
    std::cout << "After SelectionSort: \n" << testVec << "\n";
#endif

    testVec = randVec;
    t1 = std::chrono::high_resolution_clock::now();
    BubbleSort(testVec);
    t2 = std::chrono::high_resolution_clock::now();
    t = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    std::cout << "BubbleSort duration: " << t << "\n";

#ifdef PRINT_SORTED
    std::cout << "After BubbleSort: \n" << testVec << "\n";
#endif


    testVec = randVec;
    t1 = std::chrono::high_resolution_clock::now();
    NaiveSort(testVec);
    t2 = std::chrono::high_resolution_clock::now();
    t = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    std::cout << "NaiveSort duration: " << t << "\n";

#ifdef PRINT_SORTED
    std::cout << "After NaiveSort: \n" << testVec << "\n";
#endif


    return 0;
}
