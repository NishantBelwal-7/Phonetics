#include<iostream> 
#include<map>                       
#include <fstream> 
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<string, string>& a,
         pair<string, string>& b)
{
    return a.first < b.first;
}


int main() {

    map<string,string> m;


    vector<string> files = {"D:/Phonetics/dataset/aspell.txt",
                            "D:/Phonetics/dataset/birkbeck.txt",
                            "D:/Phonetics/dataset/spell-testset1.txt",
                            "D:/Phonetics/dataset/spell-testset2.txt",
                            "D:/Phonetics/dataset/wikipedia.txt"};

    for(auto &fil:files){

        ifstream inFile(fil);
        string words;
        string wrongWord;
        string correctWord;

        while(inFile >> words) {
            if(words[words.size()-1]==':'){
                correctWord = words;
                correctWord.resize(correctWord.size()-1);  
                //cout << words << endl;
            }
            else{
                wrongWord = words;
                wrongWord = wrongWord+':';
                //cout<<"Inserting in m\n";

                transform(correctWord.begin(), correctWord.end(), correctWord.begin(), ::tolower);
                transform(wrongWord.begin(), wrongWord.end(), wrongWord.begin(), ::tolower);

                m.insert({wrongWord,correctWord});
            }
        }

        inFile.close();   
    }

    cout<<"Completed";

    ofstream MyFile("D:\\Phonetics\\dataset\\CplusplusConverted.txt");

    vector<pair<string,string> >final(m.begin(),m.end());

    sort(final.begin(),final.end(),cmp);


    for(auto &x:final){
        cout<<x.first<<" "<<x.second<<"\n";
        MyFile << x.first+" "+x.second+"\n";
    }
  
    MyFile.close();        

    
             
    return 0;
}