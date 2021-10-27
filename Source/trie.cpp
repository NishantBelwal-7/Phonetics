//#include <bits/stdc++.h>
#include<iostream>


#include<iostream>
#include<string.h>
#include<algorithm>
                       
#include <fstream> 

#include <vector>

using namespace std;
 
const int ALPHABET_SIZE = 26;
 
// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
 
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};
 
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
 
    pNode->isEndOfWord = false;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}
 
// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}
 
// Returns true if key presents in trie, else
// false
bool searchTrie(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;
 
        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl->isEndOfWord);
}
 
// Driver
//int main()

struct TrieNode *insertIntoTrie()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    //string keys[] = {"the", "a", "there",
    //                "answer", "any", "by",
    //                 "bye", "their" };
    //int n = sizeof(keys)/sizeof(keys[0]);
 
    struct TrieNode *root = getNode();
 
    // Construct trie

    string fil = "D:\\Phonetics\\dataset\\All_Dictionary_Correct_Words";

    ifstream inFile(fil);
    string words;
    string correctWord;
    string incorrectWord;

    cout<<"before while"<<endl;
    while(inFile >> words) {

       //cout<<words<<endl;
        insert(root, words);
    }

    inFile.close();
    cout<<"after while";
 
   string nn;
    // Search for different keys
    //while(1){
    //   cout<<"Enter string ";
    //   cin>>nn;

    //   search(root, nn)? cout << "Yes\n" :
    //                     cout << "No\n";
    //}
    //search(root, "the")? cout << "Yes\n" :
    //                     cout << "No\n";
    //search(root, "these")? cout << "Yes\n" :
    //                       cout << "No\n";
    return root;

}