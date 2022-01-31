#include "TrieNode.h"
#include <iostream>
using namespace std;

TrieNode::TrieNode(){ //+=
    endOfWord = false;
    for (int i = 0; i < CHAR_SIZE-1; i++)
    {
    	next[i] = nullptr;
    }
}


int TrieNode::numChildren(){
    int tempChildren = 0;
    for (int i = 0; i < CHAR_SIZE-1; i++)
    {
        if (next[i])
        {
            //cout << "Has a child at " << i;
            tempChildren++;
        }
    }
}

bool TrieNode::hasChild(int toCheck){
    if (next[toCheck])
        return true;
    else
        return false;
}

bool TrieNode::hasChildren(){
    for (int i = 0; i < CHAR_SIZE-1; i++)
    {
        if (next[i])
        {
            //cout << "Has a child at " << next[i] << endl;
            return true;
        }
    }
    return false;
}   // Returns true if the TrieNode has any children
  // (i.e. any of the A-Z pointers are not nullptr)

  void TrieNode::setAsLeaf(){
      next[26] = new TrieNode();
  }

  void TrieNode::setAsInteriorNode(){
      delete next[26];
      next[26] = nullptr;
  }
  bool TrieNode::isLeaf(){
      if (next[26])
        return true;
      else
        return false;
  }
