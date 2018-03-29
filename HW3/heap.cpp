// Ömer Mesud TOKER
// 21302479

#include "heap.h"

// ctor
heap::heap():size(0)
{}

bool heap::isEmpty() const
{
    return size == 0;
}

void heap::heapInsert( const int &id, const int &priority, const int &arrival, const int &treatment)
{
    if( size >= MAX_HEAP)
        return;
    arr[size][0] = id;
    arr[size][1] = priority;
    arr[size][2] = arrival;
    arr[size][3] = treatment;

    // trickle new item up to proper location wrt
    int parent = (size - 1) / 2;
    int child = size;
    while( child > 0 && (arr[parent][1] < arr[child][1]     // 1.priority
                     || (arr[parent][1] == arr[child][1] && arr[parent][2] > arr[child][2])      // 2.arrival time
                     || (arr[parent][1] == arr[child][1] && arr[parent][2] == arr[child][2] && arr[parent][0] > arr[child][0])))  // 3. id
    {
        swap( arr[parent][0], arr[child][0]);
        swap( arr[parent][1], arr[child][1]);
        swap( arr[parent][2], arr[child][2]);
        swap( arr[parent][3], arr[child][3]);

        child = parent;
        parent = (child - 1) / 2;
    }

    ++size;
}

void heap::heapDelete( int &id, int &arrival, int &treatment)
{
    if( isEmpty())
        return;

    id = arr[0][0];         // id of deleted patient
    arrival = arr[0][2];    // arrival time of deleted patient
    treatment = arr[0][3];  // treatment time of deleted patient

    arr[0][0] = arr[--size][0];
    arr[0][1] = arr[size][1];
    arr[0][2] = arr[size][2];
    arr[0][3] = arr[size][3];

    rebuild(0);
}

void heap::rebuild( int index)
{
    int maxIndex = 2*index + 1;
    if( maxIndex >= size)    // no left child
        return;

    int rightChild = 2*index + 2;
    if( rightChild < size && arr[rightChild][1] > arr[maxIndex][1]  // 1.priority
                          || (arr[rightChild][1] == arr[maxIndex][1] && arr[rightChild][2] < arr[maxIndex][2])  // 2.arrival time
                          || (arr[rightChild][1] == arr[maxIndex][1] && arr[rightChild][2] == arr[maxIndex][2] && arr[rightChild][0] < arr[maxIndex][0]))  // 3. id
        maxIndex = rightChild;

    if( arr[index][1] < arr[maxIndex][1]    // 1.priority
        || (arr[index][1] == arr[maxIndex][1] && arr[index][2] > arr[maxIndex][2])  // 2.arrival_time
        || (arr[index][1] == arr[maxIndex][1] && arr[index][2] == arr[maxIndex][2] && arr[index][0] > arr[maxIndex][0])) // 3.id
    {
        swap( arr[index][0], arr[maxIndex][0]);
        swap( arr[index][1], arr[maxIndex][1]);
        swap( arr[index][2], arr[maxIndex][2]);
        swap( arr[index][3], arr[maxIndex][3]);
    }
    rebuild( maxIndex);
}
