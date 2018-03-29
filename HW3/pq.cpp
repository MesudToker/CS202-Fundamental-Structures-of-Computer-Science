// Ömer Mesud TOKER
// 21302479

#include "pq.h"

bool pq::isEmpty() const
{
    return h.isEmpty();
}

void pq::push( const int &id, const int &priority, const int &arrival, const int &treatment)
{
    h.heapInsert( id, priority, arrival, treatment);
}

void pq::pop( int &id, int &arrival, int &treatment)
{
    h.heapDelete( id, arrival, treatment);
}
