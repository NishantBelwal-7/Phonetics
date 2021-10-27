#include<iostream>
#include<string.h>
#include<algorithm>
#include<fstream>

using namespace std;

struct node{

    string data, correct_word;
    node *left, *right;

    node(string val, string correct) { data=val; correct_word=correct, left=right=NULL; }

};

void toLower(string &s){

    for(int i=0; i<s.length(); i++){

        if(s[i]>='A' && s[i]<='Z')
            s[i] = s[i] + ('a'-'A'); 

    }

}

node *insert(node *&root, string s, string correct_word){

    // convert strings to lowercase
    toLower(s);
    toLower(correct_word);

    if(root==NULL){
        return new node(s, correct_word);
    }

    node *newNode = new node(s, correct_word);
    node *hold_the_root = root;
    while(1){

            // Greater than 0 ( > 0): this is returned when the first string is lexicographically greater than the second string
            if(newNode->data.compare(root->data) > 0 && root->right==NULL){
                root->right = newNode;
                root=hold_the_root;
                return root;
            }
            
        else if(newNode->data.compare(root->data) > 0)
            root=root->right;

        else if(newNode->data.compare(root->data) < 0 && root->left==NULL){
            root->left = newNode;
            root = hold_the_root;
            return root;
        }

        else if(newNode->data.compare(root->data) < 0)
            root = root->left;

    }

}

string search(node *root, string s){

    // convert string to lowercase
    toLower(s);

    while(1){

        if(root==NULL) return "(" + s + ") not found";

        else if(root->data==s) return "(" + s + ") found! correct word: " + root->correct_word;

        // Greater than 0 ( > 0): this is returned when the first string is lexicographically greater than the second string   
        else if(s.compare(root->data) < 0)
            root=root->left;

        else if(s.compare(root->data) > 0)
            root = root->right;

    }
    
}

// gives sorted output
void inorder(node*root, bool correct=false){

    if(correct){

        if(root==NULL) return;

        inorder(root->left, true);
    
        for(auto i: root->correct_word)
            cout<<i;
        cout<<" ";

        inorder(root->right, true);

    }

    else{

        if(root==NULL) return;

        inorder(root->left);
    
        for(auto i: root->data)
            cout<<i;
        cout<<" ";

        inorder(root->right);
    }

}

int main(void){

    node *root = NULL;
    string root_node = "sample";

    // for root correct word and data are same
    root = insert(root, root_node, root_node);

    insert(root, "dunno", "dont know");
    insert(root, "wut", "what");
    
    insert(root, "'e'er", "ere");
    insert(root, "'eer", "ere");
    insert(root, "'er", "ere");
    insert(root, "Acceptable", "acceptable");
    insert(root, "Affi_David", "affidavit");
    insert(root, "Afi_David", "affidavit");
    insert(root, "Amanversery", "anniversary");
    insert(root, "Ameraca", "America");
    insert(root, "Ameracan", "American");
    insert(root, "Amercia", "America");
    insert(root, "Anniversary", "anniversary");
    insert(root, "Annyver", "anniversary");

    cout<<"incorrect words"<<endl;
    inorder(root);
    cout<<endl<<"========================================================================="<<endl;

    // print correct words
    cout<<"correct words:"<<endl;
    inorder(root, true); 
    cout<<endl<<"==========================================================================="<<endl;

    cout<<"search results:"<<endl;
    cout<<search(root, "Anniversary")<<endl;
    cout<<search(root, "Acceptable")<<endl; 
    cout<<search(root, "wut")<<endl; // returns corect word: what
    cout<<search(root, "abc");

}