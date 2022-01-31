#include "Trie.h"
#include <cctype>
#include <iostream>

 //Accepts string as an argument, verifies that it is alphabetical and returns a capitalized version
  string verifyAlpha(string word)
  {
      string newWord = "";
      for (int i=0; i<word.length(); i++)
      {
          if (!isalpha(word.at(i)))
            return "";
          else
            newWord.push_back(toupper(word.at(i)));
      }
      return newWord;
  }

Trie::Trie(){ // +=
    baseNode = new TrieNode();
}

bool Trie::isEmpty(){
    for (int i = 0; i < 26; i++)
    {
        if(baseNode->next[i])
        {
            return false;
        }
    }
    return true;
}

  // Inserts the word into the trie, and returns the status
  // (e.g. fail the operation if the word has any non-alphabetical
  // letter)
  bool Trie::insert(string word){
      TrieNode* previous = nullptr;
      for (int i = 0; i<word.length(); i++)
      {
          char currentChar = word.at(i);
          if (isalpha(currentChar))
          {
              currentChar = toupper(currentChar);
              int asciiChar = int(currentChar);
              if (!previous)
              {
                  if (!((baseNode->next)[asciiChar-65]))
                  {
                      previous = new TrieNode();
                      (baseNode->next)[asciiChar-65] = previous;
                      //cout <<"Creating inital array: "<< asciiChar-65 <<" with signature "<< previous <<endl;
                  }
                  else
                  {
                      previous = (baseNode->next)[asciiChar-65];
                      //cout <<"Inital character already stored, setting "<< asciiChar-65 << " as previous" <<endl;
                  }
              }
              else
              {
               // cout << "The value of the previous here is "<< (previous) << " and the 26th slot of this is "<< previous->next[26] << endl;
                  if (previous->isLeaf() || !(previous->hasChild(asciiChar-65)))
                  {
                     // cout << "A leaf is detected!" <<endl;
                      TrieNode* previousTemp = new TrieNode();
                      (previous->next)[asciiChar-65] = previousTemp;
                      previous = previousTemp;
                      //cout <<"Creating a sub array: "<< asciiChar-65 <<" with signature "<< previous << endl;
                  }
                  else
                  {
                      previous = (previous->next)[asciiChar-65];
                     // cout << "Sub array already created for "<< asciiChar-65 <<", advancing." <<endl;
                  }
              }
              //cout << "Previous: " << previous << endl;
              if ((i== word.length() -1) || (previous && !(previous->hasChildren())))
              {
                  //cout << "Setting this as a leaf." << endl;
                  if(i==word.length()-1)
                	  previous->endOfWord = true;
                  previous->setAsLeaf();
              }
              else
              {
                  //cout << "Setting this as an interior node." << endl;
                  previous->setAsInteriorNode();
              }
          }
          else
          {
              cout << "non-alphabetical value attempted, terminating insertion of word into trie." << endl;
              return false;
          }
      }
      return true;
  }
    
  void removeHelper(TrieNode* currentNode, string &s,bool &endOfWordReached)
  {
        int i = -1;
        if(s.compare("")!=0)
        {
            i = int(s.at(0))-65;
        }
        if(i>=0 && currentNode->next[i])
        {
            s = s.substr(1);
            //cout << "Pointer to this integer "<< i << " is not nullptr, so we call removeHelper with its pointer and modifed s, which is " << s << endl;
            removeHelper(currentNode->next[i],s,endOfWordReached);
        }
        if(currentNode->endOfWord==true && s.compare("")==0 && endOfWordReached == false)
        {
            endOfWordReached = true;
            currentNode->endOfWord = false;
            currentNode = nullptr;
            //cout << "End of word detected at s = "<< s << "and i = "<<i <<endl;
        }
        else if ((currentNode->hasChildren()) && (currentNode->numChildren() < 2))
        {
            //cout << "Interior node that doesn't map to anything else detected, removing this s: "<<s<< "and i= "<< i << endl;
            currentNode = nullptr;
        }
  }
  // Removes the word from the trie, and returns the status
  bool Trie::remove(string word){
      if (this->search(word))
      {
          bool endOfWordReached = false;
          string modifiedWord = verifyAlpha(word);
          removeHelper(baseNode,modifiedWord,endOfWordReached);
          return true;
      }
      else
      {
          cout<< "Removal attempted, but the word " << word <<" is not contained in the trie." << endl;
      }
      return false;
  }

  //Aids the search function with recursion and pass-by-reference variables
  void searchHelper(TrieNode* currentNode, string &s, string &word, bool &wordFound)
  {
      for (int i = 0; i < 26; i++)
        {
            if(currentNode->next[i])
            {
                string nextS = s;
                nextS.push_back(char(i+65));
                searchHelper(currentNode->next[i],nextS,word,wordFound);

            }
        }
        if(currentNode->endOfWord==true)
        {
            if(s.compare(word)==0)
            {
                wordFound = true;
            }
        }
  }



  // Returns true if the word is present in the trie, false otherwise
  bool Trie::search(string word){
      string verifiedWord = verifyAlpha(word);
      if (verifiedWord!="")
      {
          string s = "";
          bool wordFound = false;
          searchHelper(baseNode,s,verifiedWord,wordFound);
          return wordFound;
      }
      else
        return false;
  }

  //Recursive helper function for outputting words in the trie
    void displayHelper(TrieNode* currentNode, string &s){
        for (int i = 0; i < 26; i++)
          {
              if(currentNode->next[i]!=nullptr)
              {
                  string nextS = s;
                  nextS.push_back(char(i+65));
                  displayHelper(currentNode->next[i],nextS);

              }
          }
          if(currentNode->endOfWord==true)
          {
              cout << s << endl;
          }
    }

    // Displays all the words currently in the trie
    void Trie::displayWordList(){
        string s = "";
        displayHelper(baseNode, s);
    }
