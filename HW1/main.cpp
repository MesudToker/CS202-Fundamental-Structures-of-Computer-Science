// Ömer Mesud TOKER
// 21302479 - Section 1

#include <iostream>
#include "sorting.cpp"
#include "sorting.h"
#include "time.h"
#include <ctime>
#include <time.h>
#include <stdio.h>
#include <string>
#include <cstdlib> // srand(), rand()

using std::string;
using namespace std;


int main()
{
    srand( time( NULL));
    double duration;
    clock_t startTime;

    sorting s;

    int length = 100000;

    cout << "sizes of the arrays : " << length << endl;



    int a1[length];
    for(int i = 0; i < length ; i++) {
        int randomNumber = rand()% 100000;
        a1[i] = randomNumber;
    }
/*
    cout << "PART 1" << endl;

    // Creating second copy
    int a2[length];
    for(int i = 0; i < length ; i++) {
        a2[i] = a1[i];
    }
    // Creating third copy
    int a3[length];
    for(int i = 0; i < length ; i++){
        a3[i] = a1[i];
    }

    int compCount = 0;
    int moveCount = 0;

    // Bubble sort
    startTime = clock();
    s.bubbleSort(a1,length,compCount,moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Elapsed Time in millisecond for bubble sort: " << duration << endl;
    cout << "For Bubble Sort" << endl;
    cout << "Number of Key Comparisons: " << compCount << endl;
    cout << "Number of Data Moves: " << moveCount << endl;

    // merge sort
    compCount = 0;
    moveCount = 0;
    startTime = clock();
    s.mergeSort(a2,length,compCount,moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Elapsed Time in millisecond for merge sort: " << duration << endl;
    cout << "For Merge Sort" << endl;
    cout << "Number of Key Comparisons: " << compCount << endl;
    cout << "Number of Data Moves: " << moveCount << endl;

    // quick sort
    compCount = 0;
    moveCount = 0;
    startTime = clock();
    s.quickSort(a3,length,compCount,moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Elapsed Time in millisecond for quick sort: " << duration << endl;
    cout << "For Quick Sort" << endl;
    cout << "Number of Key Comparisons: " << compCount << endl;
    cout << "Number of Data Moves: " << moveCount << endl;


    cout << "PART 2" << endl;

    int compCount = 0;
    int moveCount = 0;
    s.quickSort(a1,length,compCount,moveCount);

    int ad1[length];
    for(int i = 0; i < length ; i++) {
        ad1[i] = a1[length - 1 - i];
    }

    int ad2[length];
    for(int i = 0; i < length ; i++) {
        ad2[i] = ad1[i];
    }

    int ad3[length];
    for(int i = 0; i < length ; i++){
        ad3[i] = ad1[i];
    }

    // Bubble sort
    compCount = 0;
    moveCount = 0;
    startTime = clock();
    s.bubbleSort(ad1,length,compCount,moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Elapsed Time in millisecond for bubble sort: " << duration << endl;
    cout << "For Bubble Sort" << endl;
    cout << "Number of Key Comparisons: " << compCount << endl;
    cout << "Number of Data Moves: " << moveCount << endl;

    // merge sort
    compCount = 0;
    moveCount = 0;
    startTime = clock();
    s.mergeSort(ad2,length,compCount,moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Elapsed Time in millisecond for merge sort: " << duration << endl;
    cout << "For Merge Sort" << endl;
    cout << "Number of Key Comparisons: " << compCount << endl;
    cout << "Number of Data Moves: " << moveCount << endl;

    // quick sort
    compCount = 0;
    moveCount = 0;
    startTime = clock();
    s.quickSort(ad3,length,compCount,moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Elapsed Time in millisecond for quick sort: " << duration << endl;
    cout << "For Quick Sort" << endl;
    cout << "Number of Key Comparisons: " << compCount << endl;
    cout << "Number of Data Moves: " << moveCount << endl;
*/
    cout << "PART 3" << endl;

    int compCount = 0;
    int moveCount = 0;
    s.quickSort(a1,length,compCount,moveCount);

    int aa1[length];
    for(int i = 0; i < length ; i++) {
        aa1[i] = a1[i];
    }

    int aa2[length];
    for(int i = 0; i < length ; i++) {
        aa2[i] = a1[i];
    }

    int aa3[length];
    for(int i = 0; i < length ; i++){
        aa3[i] = a1[i];
    }

    // Bubble sort
    compCount = 0;
    moveCount = 0;
    startTime = clock();
    s.bubbleSort(aa1,length,compCount,moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Elapsed Time in millisecond for bubble sort: " << duration << endl;
    cout << "For Bubble Sort" << endl;
    cout << "Number of Key Comparisons: " << compCount << endl;
    cout << "Number of Data Moves: " << moveCount << endl;

    // merge sort
    compCount = 0;
    moveCount = 0;
    startTime = clock();
    s.mergeSort(aa2,length,compCount,moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Elapsed Time in millisecond for merge sort: " << duration << endl;
    cout << "For Merge Sort" << endl;
    cout << "Number of Key Comparisons: " << compCount << endl;
    cout << "Number of Data Moves: " << moveCount << endl;

    // quick sort
    compCount = 0;
    moveCount = 0;
    startTime = clock();
    s.quickSort(aa3,length,compCount,moveCount);
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Elapsed Time in millisecond for quick sort: " << duration << endl;
    cout << "For Quick Sort" << endl;
    cout << "Number of Key Comparisons: " << compCount << endl;
    cout << "Number of Data Moves: " << moveCount << endl;

    return 0;
}
