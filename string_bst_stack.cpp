
#include<iostream>
#include<string.h>
#include<algorithm>
                       
#include <fstream> 

#include <vector>
using namespace std;

//struct Node{
  //  char correctdata[50];
   // char incorrectdata[50];
  //  struct Node* right;
   // struct Node* left;
//};

struct Node{

    string data, correct_word="correct word";
    Node *left, *right;

    Node(string val, string correct) { data=val; correct_word=correct, left=right=NULL; }

};


typedef struct Node* NODE;

NODE createNode(string s, string correct_word){
    NODE newNode = new Node(s, correct_word);

if(!newNode){
    cout<<"Not enough memory"<<endl;
    exit(-1);
}
newNode->left = NULL;
newNode->right = NULL;
newNode->data=s;
newNode->correct_word=correct_word;
return (newNode);
}




void insertNode(NODE* head,string s,string correctdata){

    NODE newNode = createNode(s,correctdata);
    NODE hold_the_head = *head;
    if(*head == NULL){
        *head = newNode;
        (*head)->right = NULL;
        (*head)->left = NULL;
        return;
    }

    while(1){
        if((newNode->data>(*head)->data)&&((*head)->right==       NULL)){
            (*head)->right = newNode;
            *head = hold_the_head;
            return;
        }
        else if( newNode->data > (*head)->data ){
            (*head) = (*head)->right;
        }

        else if( (newNode->data < (*head)->data) && ( (*head)->left ==   NULL ) ){
            (*head)->left = newNode;
            *head = hold_the_head;
            return;
        }
        else if( newNode->data < (*head)->data ){
            (*head) = (*head)->left;
        }
    }
}

void inOrderTraversal(NODE node){

    if(node == NULL)
       return;
    inOrderTraversal(node->left);
    cout<<node->data<<"\t"<<node->data<<endl;
    inOrderTraversal(node->right);
}


string searchTree(NODE root, string s){

    // convert string to lowercase
    //toLower(s);

    while(1){

        if(root==NULL) return "NATAZXX";

        else if(root->data==s) return  root->correct_word;

        // Greater than 0 ( > 0): this is returned when the first string is lexicographically greater than the second string   
        else if(s.compare(root->data) < 0)
            root=root->left;

        else if(s.compare(root->data) > 0)
            root = root->right;

    }
    
}


NODE insertionIntoTree(){

    NODE head = NULL;
    string fil = "D:\\Phonetics\\dataset\\CplusplusConverted.txt";

    ifstream inFile(fil);
    string words;
    string correctWord;
    string incorrectWord;

    while(inFile >> words) {
        //cout<<words<<endl;
        if(words[words.size()-1]==':'){
            incorrectWord = words;
            incorrectWord.resize(incorrectWord.size()-1);  

            
            //cout<<"if"<<words<<endl;
            //cout << words << endl;
        }
        

        else{
            correctWord = words;

            //int correctSize = correctWord.size();
            //int incorrectSize = incorrectWord.size();
            //cout<<"Inserting in m\n";
            

            insertNode(&head, incorrectWord, correctWord);
            //cout<<"Inserting"<<incorrectWord<<endl;
        }
        //cout<<"Condition checking\n\n";
    }

    inFile.close();   

    cout<<"Insertion complete"<<endl;

    return head;

}
/*
int main(){

    NODE head = NULL;

    string fil = "D:\\Phonetics\\dataset\\CplusplusConverted.txt";

    ifstream inFile(fil);
    string words;
    string correctWord;
    string incorrectWord;

    while(inFile >> words) {
        //cout<<words<<endl;
        if(words[words.size()-1]==':'){
            incorrectWord = words;
            incorrectWord.resize(incorrectWord.size()-1);  

            
            //cout<<"if"<<words<<endl;
            //cout << words << endl;
        }
        

        else{
            correctWord = words;

            int correctSize = correctWord.size();
            int incorrectSize = incorrectWord.size();
            //cout<<"Inserting in m\n";
            

            head = insertNode(&head, incorrectWord, correctWord);
            //cout<<"Inserting"<<incorrectWord<<endl;
        }
        //cout<<"Condition checking\n\n";
    }

    inFile.close();   

    cout<<"Insertion complete"<<endl;



    //inOrderTraversal(head);

    cout<<search(head,"cycolodgy");

    cout<<endl;
    return 0;
}
*/