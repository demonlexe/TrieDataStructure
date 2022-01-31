/*
 * TermProject.cpp
 *
 * Course: CS 2337.501
 * Term: Fall 2021
 * Author: Alexis Kaufman
 * UTD-id: ahk200001
 *
 *  In this project, I implemented a Trie data structure utilizing the
 * TrieNode and Trie classes. TrieNode consists of a struct with two member variables,
 * a boolean that determines if the TrieNode ends a word and an array of pointers to TrieNodes.
 * The Trie class constructs a trie that has a root node, named baseNode,
 * which points to an array of size 27 that has a sentinel as the 27th value, holding
 * either a pointer to itself (meaning it is a leaf) or a null pointer
 * (meaning it is an interior node). Therefore, the word "TIN" could be represented
 * as TIN$ and the word "THERE" could be represented as THERE$, etc. The program
 * consists of methods for inserting, removing, searching, and displaying
 * words in the trie.
 *
 */
#include <iostream>
#include <fstream>
using namespace std;

#include "Trie.h"

void displayWordStatus(Trie* trieObj, string word) {
    string status = trieObj->search(word)? " present " : " not present ";
    cout << "Word " << word << status << "in the Trie" << endl;
}

// C++ implementation of TrieNode data structure
int main(int argc, char* argv[])
{
    if(argc == 1) {
        cerr << "Filename not provided\n";
        cerr << "usage: " << argv[0] << " <filename>\n";
        return 1;
    }
    
    Trie* trieObj = new Trie();

    
    string filename = argv[1];
    ifstream ifs(filename);
    string word;
    
    // Test for populating the trie data structure from file
    while(ifs>>word) {
        if(word[0] == '#') continue;
        trieObj->insert(word);
    }
    
    // Test for deletion of non-existent word
    string word0 = "gibberishwordnotintree";
    trieObj->remove(word0);
    
    // Test for adding a new word on the fly
    string word1 = "utdallas";
    displayWordStatus(trieObj, word1);
    trieObj->insert(word1);
    displayWordStatus(trieObj, word1);
    
    // Test for deleting a shorter word, without impacting a longer word
    // for which the former is a prefix
    string word2 = "atom";
    displayWordStatus(trieObj, word2);
    trieObj->remove(word2);
    displayWordStatus(trieObj, word2);

    string word3 = "atomic";
    displayWordStatus(trieObj, word3);
    
    // Test for deleting a longer word, without impacting a shorter word
    // for which the latter is a prefix
    string word4 = "girlish";
    displayWordStatus(trieObj, word4);
    trieObj->remove(word4);
    displayWordStatus(trieObj, word4);
    
    string word5 = "girl";
    displayWordStatus(trieObj, word5);
    
	return 0;
}
