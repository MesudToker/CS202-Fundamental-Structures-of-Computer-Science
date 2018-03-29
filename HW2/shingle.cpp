// Ömer Mesud TOKER
// 21302479 - Section 1

// shingle.h
//ShingleTree class
#include "shingle.h"
#include <algorithm>
#include <fstream>
#include<string>
#include <cstdlib>
#include <iostream>

using namespace std;

ShingleTree::ShingleTree() {
    root = NULL;
    nodeCount = 0;
}

ShingleTree::~ShingleTree() {
    destroyShingleTree(root);
}

void ShingleTree::destroyShingleTree(ShingleNode *& nodePtr) {
    if (nodePtr !=NULL ) {
        destroyShingleTree(nodePtr -> left);
        destroyShingleTree(nodePtr -> right);
        delete nodePtr;
        nodePtr = NULL;
    }
}

int ShingleTree::compareArrays(string a1[], string a2[]) {
    int i = 0;
    do {
        if(a1[i]<a2[i])
            return -1;
        if(a1[i]>a2[i])
            return 1;
        i++;
    } while(a1[i] != NULL && a2[i] != NULL);

    if (a1[i] != NULL) {
        return 1;
    }
    else {
        if (a2[i] != NULL)
            return -1;
    }
    return 0;
}

ShingleTree::ShingleNode* ShingleTree::findPlace(string shingle[], ShingleNode * root) {
    if (compareArrays(shingle, root -> item) == 1) {
        if (root->right != NULL)
            return findPlace(shingle, root->right);
    }
    else if ( compareArrays(shingle, root -> item) == -1 ) {
        if (root->left != NULL)
            return findPlace(shingle, root->left);
    }
    else {
        root->count++;
        return NULL;
    }
    return root;
}

void ShingleTree::addShingle(string shingle[]) {
    for ( int i = 0; shingle[i] != NULL; i++) {
        transform(shingle[i].begin(), shingle[i].end(), shingle[i].begin(), ::tolower );
    }

    if (root == NULL) {
        root = new ShingleNode(shingle, NULL, NULL);

        nodeCount =1;
    }
    else {
        ShingleNode *node = findPlace(shingle, root);
        if (node == NULL)
            return;
        if ( compareArrays(shingle, node->item) == 1)
            node->right = new ShingleNode( shingle, NULL, NULL );
        else
            node->left = new ShingleNode( shingle, NULL, NULL );

        nodeCount++;
    }
}

void ShingleTree::generateTree( string fileName, int k) {
    if( k <= 0) {
        cout << "k must be positive!" << endl;
        return;
    }

    ifstream in( fileName.c_str());
    if( !in.is_open())  // file is not opened
        cout << "File cannot be opened!" << endl;

    string arr[k];
    for( int i = 1; i <= k-1; ++i)
        in >> arr[i-1];
    while( in >> arr[k-1]) {
        addShingle( arr);
        for( int i = 0 ; i < k-1; ++i)
            arr[i] = arr[i+1];
    }
}

int ShingleTree::getDistinctShingleCount() {
    return nodeCount;
}

int ShingleTree::getNumberOfShinglesThatStartWith( string firstWord) {
    return calculate_shingles_start_with( firstWord, root);
}

int ShingleTree::calculate_shingles_start_with( const string &firstWord, ShingleNode *root) {
    if( root == NULL)
        return 0;
    bool found = false;
    for(int i =0; root->item[i] != NULL; i++) {
        if(root->item == firstWord)
            found = true;
    }

    if( found )
        return 1 + calculate_shingles_start_with( firstWord, root->left) + calculate_shingles_start_with( firstWord, root->right);
    else
        return calculate_shingles_start_with( firstWord, root->left) + calculate_shingles_start_with( firstWord, root->right);
}

void ShingleTree::printAllShinglesAndFreqs() {
    print( "", root);
}

void ShingleTree::printShinglesThatStartWith( string firstWord){
    print( firstWord, root);
}

void ShingleTree::print( const string &firstWord, ShingleNode *root) {
    if (root != NULL) {
        print(firstWord, root->left);

        bool found = false;
        for(int i =0; root->item[i] != NULL; i++) {
        if(root->item == firstWord)
            found = true;
        }

        if (found) {
            for (int i = 0; root->item[i] != NULL; i++){
                cout << root->item[i] << " ";
            }
            cout << ": " << root->count << endl;
        }

        print(firstWord, root->right);
    }
}

bool ShingleTree::isComplete() {

}

int ShingleTree::getHeight() {
    return calculate_height(root);
}

int ShingleTree::calculate_height( ShingleNode *root) {
    if( root == NULL)
        return 0;
    return 1 + max( calculate_height( root->left), calculate_height( root->right));
}
