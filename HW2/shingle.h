// Ömer Mesud TOKER
// 21302479 - Section 1

// shingle.h
//ShingleTree class
#include<string>

using namespace std;

class ShingleTree
{
    public:
        ShingleTree();
        ~ShingleTree();
        void addShingle(string shingle[]) ; // string array of size k
        void generateTree(string fileName, int k);
        int getDistinctShingleCount();
        int getNumberOfShinglesThatStartWith(string firstWord) ;
        void printAllShinglesAndFreqs();
        void printShinglesThatStartWith(string firstWord) ;
        bool isComplete();
        int getHeight() ;

    private:
        struct ShingleNode {
            ShingleNode();

            ShingleNode( string *item, ShingleNode *left = NULL, ShingleNode *right = NULL) {
                this -> item = item;
                this -> left = left;
                this -> right = right;
                count = 1;
            }

            ShingleNode *left, *right;
            string *item;
            int count;
        } ;

        ShingleNode *root;
        int nodeCount;

        void destroyShingleTree( ShingleNode *& nodePtr);
        int compareArrays(string a1[], string a2[]);
        ShingleNode * findPlace( string shingle[], ShingleNode * root);
        int calculate_shingles_start_with( const string &firstWord, ShingleNode *root);
        void print( const string &firstWord, ShingleNode *root);
        int calculate_height( ShingleNode *root);

};

