// Ömer Mesud TOKER
// 21302479 - Section 1

#include "shingle.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    ShingleTree tree;
    string fileName(argv[1]);
    int k = atoi(argv[2]);

    tree.generateTree(fileName, k);
    cout << "Total distinct " << k << "-shingle count: " << tree.getDistinctShingleCount() << endl;
    tree.printAllShinglesAndFreqs();
    cout << endl << k << "-shingle tree is complete: " << (tree.isComplete() ? "Yes" : "No") << endl;
    cout << "Height of the " << k << "-shingle tree: " << tree.getHeight() << endl;

    string firstWord = "peppers";
    cout << endl << "There are " << tree.getNumberOfShinglesThatStartWith(firstWord) << " " << k << "-shingles that start with " << firstWord << ": " << endl;
    tree.printShinglesThatStartWith(firstWord);

    firstWord = "rain" ;
    cout << endl << "There are " << tree.getNumberOfShinglesThatStartWith(firstWord) << " " << k << "-shingles that start with " << firstWord << ": " << endl;
    tree.printShinglesThatStartWith(firstWord);

    return 0;
}
