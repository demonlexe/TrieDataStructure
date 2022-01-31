#ifndef _TRIENODE_H_
#define _TRIENODE_H_

struct TrieNode
{
  const static int CHAR_SIZE = 27;

  TrieNode ();

  // Returns true if the TrieNode has any children
  // (i.e. any of the A-Z pointers are not null)
  bool hasChildren();

  bool hasChild(int toCheck); //Checks if the node contains this value

  int numChildren(); //Returns the number of children

  // Set the '$' pointer to a valid non-null address
  void setAsLeaf();

  // Set the '$' pointer to null
  void setAsInteriorNode();

  // Returns true if the '$' pointer is not-null
  bool isLeaf();

  TrieNode *next[CHAR_SIZE];
  bool endOfWord;
};
#endif // _TRIENODE_H_
