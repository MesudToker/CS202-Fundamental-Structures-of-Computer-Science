// Ömer Mesud TOKER
// 21302479

#include "simulator.h"
#include <stdlib.h> // for atoi
using namespace std;

int main( int argc, char **argv)
{
    // pass file name and max average to simulator
    simulator sm( argv[1], atoi(argv[2]));

    // call simulate
    sm.simulate();

    return 0;
}
