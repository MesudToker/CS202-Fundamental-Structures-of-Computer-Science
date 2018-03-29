// Ömer Mesud TOKER
// 21302479

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

class heap
{
    public:
        heap();
        bool isEmpty() const;
        void heapInsert( const int &id, const int &priority, const int &arrival, const int &treatment);
        void heapDelete( int &id, int &arrival, int &treatment);

    private:
        void rebuild( int index);

        static const int MAX_HEAP = 200;
        int arr[MAX_HEAP][4];   // id - priority - arrivalTime - treatmentTime
        int size;
};

#endif // HEAP_H
