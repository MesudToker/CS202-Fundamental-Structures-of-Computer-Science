// Ömer Mesud TOKER
// 21302479
//Section 1

#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <DictionaryBST.h>
#include <sstream>
#include <string>
using namespace std;



DictionaryBST::DictionaryBST( string DictionaryFile ) {
    root = NULL;

    ifstream file;
    file.open(DictionaryFile);

    string word;

    while(file >> word)
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        this->insert(word);
    }
    file.close();

}
DictionaryBST::~DictionaryBST() {

}

void DictionaryBST::insert(string word) {

    node *temp;
    node *previous;

    if(root == NULL) {
        node *newNode = new node;
        newNode->word = word;
        newNode->left = NULL;
        newNode->right = NULL;

        root = newNode;
   }
   else {
        temp = root;
        while(temp != NULL) {

            if((temp->word) == word) {
                //return false;
            }

            if(word < (temp->word)){
                previous = temp;
                temp = temp -> left;
            }
            else {
                previous = temp;
                temp = temp -> right;
            }
        }

        node *addNode = new node;

        addNode->word = word;
        addNode->left = NULL;
        addNode->right = NULL;

        if(word < (previous->word))
            previous->left = addNode;
        else
            previous->right = addNode;
   }
}

void DictionaryBST::search(string word, int& numComparisons, bool& found) {
    numComparisons = 0;
    found = false;

    if (root == NULL ) {
        numComparisons++;

    }
    else if(root->word == word) {
        numComparisons++;
        found = true;
    }
    else {
        node* temp = root;
        while(temp != NULL) {
            if((temp->word) == word) {
                numComparisons++;
                found = true;
                break;
            }

            if(word < (temp->word)) {
                numComparisons++;
                temp = temp -> left;
            }
            else {
                numComparisons++;
                temp = temp -> right;
            }
        }
    }


}


void DictionaryBST::search(string queryFile, string outputFile) {
    string line = "";
    stringstream ss;           //to cancatenate strings

    int comparNum, oneOrTwo, numOfQueries = 0;
    bool found;

    ifstream file;
    file.open(queryFile);

    ofstream fileOut;
    fileOut.open(outputFile);
    string word;

    ifstream arrayFile;
    arrayFile.open(queryFile);

    int arraySize = 0;          //to determine the array size
    while(arrayFile >> word) {
        arraySize++;
    }
    arrayFile.close();



    int numOfComparisons[arraySize];          //array to hold all of comparisons
    int index = 0;

    while(file >> word) {
        stringstream ss;
        transform(word.begin(), word.end(), word.begin(), ::tolower);  //case insensitive
        search(word,comparNum, found);

        numOfComparisons[index] = comparNum;

        if(found == true) {
            oneOrTwo = 1;
        }
        else {
            oneOrTwo = 0;
        }
        ss << word <<" " << oneOrTwo<<" " <<comparNum<<" \n";      //gather and write stats to file
        line = ss.str();
        fileOut << line;


        numOfQueries++;
        index++;
    }

    int maximum = 1;
    double sum = 0;

    for(int i = 0; i < arraySize; i++) {
        sum += numOfComparisons[i];
        if(maximum < numOfComparisons[i])
            maximum = numOfComparisons[i];
    }

    double average = sum/arraySize;

    fileOut << "# of queries: " << numOfQueries<< " \n";
    fileOut << "Maximum # of comparisons: " << maximum<< " \n";
    fileOut << "Average # of comparisons: " << average<< " \n";


    file.close();
    fileOut.close();

}

void DictionaryBST::inorder(struct node* root) {
    if(root != NULL) {
        inorder(root->left);
        cout<< root->word<<endl;
        inorder(root->right);
    }
}
