
#ifndef _TRIE_H_
#define _TRIE_H_
#include <string>
#include "TrieNode.h"
using namespace std;

class Trie {
public:
  Trie();

  // Returns true if the trie is empty, false otherwise
  bool isEmpty();

  // Inserts the word into the trie, and returns the status
  // (e.g. fail the operation if the word has any non-alphabetical
  // letter)
  bool insert(string word);

  // Removes the word from the trie, and returns the status
  bool remove(string word);

  // Returns true if the word is present in the trie, false otherwise
  bool search(string word);

  // Displays all the words currently in the trie
  void displayWordList();

private:
TrieNode* baseNode;
//
};
#endif // _TRIE_H_
