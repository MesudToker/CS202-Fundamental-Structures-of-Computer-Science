// Ömer Mesud TOKER
// 21302479 - Section 1

#include <iostream>
#include "sorting.h"
#include <algorithm>

using std::string;

sorting::sorting()
{
    //ctor
}

void sorting::swap( int &x, int &y, int &moveCount) {
    int temp = x;
    x = y;
    y = temp;
    moveCount = moveCount + 3;
}

void sorting::bubblesort( int theArray[], int n, int &compCount, int &moveCount) {
    bool sorted = false;

	for (int pass = 1; (pass < n) && !sorted; ++pass) {
        sorted = true;

        for (int index = 0; index < n-pass; ++index) {
            int nextIndex = index + 1;
            compCount++;
            if (theArray[index] > theArray[nextIndex]) {

                swap(theArray[index], theArray[nextIndex], moveCount);
                sorted = false; // signal exchange
         }
      }
   }
}


void sorting::mergesort( int theArray[], int first, int last, int &compCount, int &moveCount) {

    if (first < last) {

        int mid = (first + last)/2; 	// index of midpoint

        mergesort(theArray, first, mid,compCount, moveCount);

        mergesort(theArray, mid+1, last,compCount,moveCount);

        // merge the two halves
        merge(theArray, first, mid, last,compCount,moveCount);
   }
}       // end mergesort

void sorting::merge( int theArray[], int first, int mid, int last,int &compCount, int &moveCount) {

    int tempArray[100000]; 	// temporary array

    int first1 = first; 	// beginning of first subarray
    int last1 = mid; 		// end of first subarray
    int first2 = mid + 1;	// beginning of second subarray
    int last2 = last;		// end of second subarray
    int index = first1; // next available location in tempArray

    for ( ; (first1 <= last1) && (first2 <= last2); ++index) {

        compCount++;
        if (theArray[first1] < theArray[first2]) {
        tempArray[index] = theArray[first1];
        moveCount++;

        ++first1;
        }
        else {
            tempArray[index] = theArray[first2];
            moveCount++;
            ++first2;
        }
   }
// finish off the first subarray, if necessary

    for (; first1 <= last1; ++first1, ++index) {
        tempArray[index] = theArray[first1];

        moveCount++;
    }
    // finish off the second subarray, if necessary

    for (; first2 <= last2; ++first2, ++index) {
        tempArray[index] = theArray[first2];

        moveCount++;
    }

   // copy the result back into the original array

    for (index = first; index <= last; ++index) {
        theArray[index] = tempArray[index];

        moveCount++;
    }
}  // end merge


void sorting::quicksort(int theArray[], int first, int last,int &compCount, int &moveCount) {
// Precondition: theArray[first..last] is an array.
// Postcondition: theArray[first..last] is sorted.

	int pivotIndex;

    if (first < last) {

      // create the partition: S1, pivot, S2
        partition(theArray, first, last, pivotIndex,compCount,moveCount);

      // sort regions S1 and S2
        quicksort(theArray, first, pivotIndex-1,compCount, moveCount);
        quicksort(theArray, pivotIndex+1, last,compCount, moveCount);
   }
}
void sorting::partition(int theArray[], int first, int last,int &pivotIndex,int &compCount, int &moveCount) {
   // Precondition: theArray[first..last] is an array; first <= last.
   // Postcondition: Partitions theArray[first..last] such that:
   //   S1 = theArray[first..pivotIndex-1] < pivot
   //   theArray[pivotIndex] == pivot
   //   S2 = theArray[pivotIndex+1..last] >= pivot

	// place pivot in theArray[first]
   choosePivot(theArray, first, last,compCount,moveCount);

   int pivot = theArray[first]; // copy pivot
   moveCount++;
// initially, everything but pivot is in unknown
   int lastS1 = first;           // index of last item in S1
   int firstUnknown = first + 1; // index of first item in unknown

	// move one item at a time until unknown region is empty

   for (  ; firstUnknown <= last; ++firstUnknown) {
      // Invariant: theArray[first+1..lastS1] < pivot
      //            theArray[lastS1+1..firstUnknown-1] >= pivot

      // move item from unknown to proper region
      compCount++;
      if (theArray[firstUnknown] < pivot) {  	// belongs to S1
		  ++lastS1;
    	  swap(theArray[firstUnknown], theArray[lastS1], moveCount);

      }	// else belongs to S2
   }
   // place pivot in proper position and mark its location
   swap(theArray[first], theArray[lastS1], moveCount);

   pivotIndex = lastS1;
}
void sorting::choosePivot(int theArray[], int first, int last,int &compCount, int &moveCount)
{
    swap(theArray[first], theArray[last], moveCount);
}

void sorting::bubbleSort( int *arr, int size, int &compCount,int &moveCount)
{
    bubblesort( arr, size,compCount,moveCount);
}
void sorting::mergeSort( int *arr, int size,int &compCount,int &moveCount)
{
    int x = 0;
    int y = size-1;
    mergesort( arr, x, y,compCount,moveCount);
}
void sorting::quickSort( int *arr, int size,int &compCount,int &moveCount)
{
    int x = 0;
    int y = size-1;
    quicksort(arr, x, y,compCount,moveCount);
}



