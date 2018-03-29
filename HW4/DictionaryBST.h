// Ömer Mesud TOKER
// 21302479
//Section 1

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include <string>
using namespace std;

struct node
{
    string word;
    node* left;
    node* right;
};

class DictionaryBST
{
    public:
        //Constructor that constructs the dictionary from the input file
        DictionaryBST( string dictionaryFile );
        //Destructor
        ~DictionaryBST();
        //Inserts the given word into the dictionary
        void insert( string word );
        //Searches the given word in the dictionary, and returns the number
        //of comparisons made and whether the word is found or not
        void search( string word, int& numComparisons, bool& found );
        //Searches all words in the query file in the dictionary, and
        //summarizes the results in the output file
        void search( string queryFile, string outputFile );

        void inorder(struct node* root);
        struct node* insertNode(struct node* node, string str);
        struct node* newNode(string str);
    //private:
        node* root;
};
