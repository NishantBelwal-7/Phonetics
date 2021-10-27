#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

struct node{

    string data, correct_word;
    node *left, *right;

    node(string val, string correct) { data=val; correct_word=correct, left=right=NULL; }

};

node *insert(node *&root, string s, string correct_word){

    if(root==NULL){
        return new node(s, correct_word);
    }

    // Greater than 0 ( > 0): this is returned when the first string is lexicographically greater than the second string
    if(s.compare(root->data) < 0)
        root->left = insert(root->left, s, correct_word);

    else root->right = insert(root->right, s, correct_word);

    return root;

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

string search(node *root, string s){

    if(root==NULL) return "(" + s +") not found";

    if(root->data==s) return "(" + s + ") found! correct word: " + root->correct_word;

    if(s.compare(root->data) < 0)
        return search(root->left, s);

    else return search(root->right, s);
    
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
    inorder(root); // dunno sample wut
    cout<<endl<<"========================================================================="<<endl;

    // print correct words
    cout<<"correct words:"<<endl;
    inorder(root, true); // dont know sample what
    cout<<endl<<"==========================================================================="<<endl;

    cout<<"search results:"<<endl;
    cout<<search(root, "Acceptable")<<endl; // not found
    cout<<search(root, "wut")<<endl; // returns corect word: what
    cout<<search(root, "abc");

}