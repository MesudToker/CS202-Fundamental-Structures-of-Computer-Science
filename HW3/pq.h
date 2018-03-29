// Ömer Mesud TOKER
// 21302479

#ifndef PQ_H
#define PQ_H

#include "heap.h"

class pq
{
    public:
        bool isEmpty() const;
        void push( const int &id, const int &priority, const int &arrival, const int &treatment);
        void pop( int &id, int &arrival, int &treatment);

    private:
        heap h;
};

#endif // PQ_H
