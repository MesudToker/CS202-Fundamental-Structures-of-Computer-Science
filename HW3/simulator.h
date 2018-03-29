// Ömer Mesud TOKER
// 21302479

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <iostream>
#include <fstream>
#include "pq.h"
#include "algorithm" // for max()
using namespace std;

class simulator
{
    public:
        simulator( const char *fileName, int maxAverage);
        void simulate();
    private:
        int maxAverage;
        const char *fileName;
};

#endif // SIMULATOR_H
