#include<iostream>
#include<sstream>
#include<string>

#include"D:\Phonetics\Source\string_bst_stack.cpp"
#include"D:\Phonetics\Source\trie.cpp"
#include"D:\Phonetics\Source\correctBinary.cpp"
#include"D:\Phonetics\Source\incorrectCorrectTrie.cpp"

using namespace std;

int main(){


    struct TrieNode* correctTreeHead = insertIntoTrie();
    cout<<"Correct Trie build"<<endl;

    //NODE treeHead = insertionIntoTree();
    //NODE treeHead = NULL;
    //Trie* trieHead = insertionIntoTrie();
    
    struct TrieNodeCIN* correctIncorrectTreeHead = insertIntoCorrectIncorrectTrie();
    cout<<"Incorrect Trie build\n";
    string check;
    char condition = 'y';
    
    //inOrderTraversalTree(*correctTreeHead);
    
    while(condition=='y'){

        
        cout<<"\nEnter a string - ";
        getline(cin,check);

        istringstream iss(check);
        string x;
        while(iss>>x) {

            //toLower(x);
            if(searchTrie(correctTreeHead,x)!=true){

                if( searchTrieCIN(correctIncorrectTreeHead,x) =="NATAZXX"){
                    cout<<x<<" \t";
                }
                else{
                    cout<<searchTrieCIN(correctIncorrectTreeHead,x)<<" ";
                }
                /*if(searchTree(treeHead,x)=="NATAZXX"){
                    cout<<x<<"\t";
                }
                else{
                    cout<<searchTree(treeHead,x);
                }*/
                
            }
            else{
                cout<<x<<" \t";
            }

        }

    }
    

    //cout<<searchTree(treeHead,"cycolodgy");
}