// Ömer Mesud TOKER
// 21302479 - Section 1

#include <iostream>
#ifndef SORTING_H
#define SORTING_H

using std::string;
class sorting
{
    public:
        sorting();

        void swap ( int &x, int &y, int &moveCount);

        void bubblesort( int theArray[], int n,int &compCount, int &moveCount);

        void mergesort( int theArray[], int first, int last,int &compCount, int &moveCount);
        void merge( int theArray[], int first, int mid, int last, int &compCount, int &moveCount);

        void quicksort(int theArray[], int first, int last,int &compCount, int &moveCount);
        void partition(int theArray[], int first, int last,int &pivotIndex, int &compCount, int &moveCount);
        void choosePivot(int theArray[], int first, int last,int &compCount, int &moveCount);

        void bubbleSort( int *arr, int size, int &compCount, int &moveCount);
        void mergeSort( int *arr, int size, int &compCount, int &moveCount);
        void quickSort( int *arr, int size, int &compCount, int &moveCount);

    protected:

    private:

};

#endif // SORTING_H

