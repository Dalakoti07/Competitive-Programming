#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    map<char,int> childrenCount;
    bool isLast;
    map<char,TrieNode*> children;

    TrieNode(){
        this->isLast=false;
    }

    void insertWord(string word){
        char c;
        int n =word.length();
        TrieNode* current =this;
        for(int i=0;i<n;i++){
            c=word[i];
            if(current->children.find(c)==current->children.end()){
                (current->children)[c]=new TrieNode();
                (current->childrenCount)[c]=1;
            }else{
                (current->childrenCount)[c]+=1;
            }
            current=(current->children)[c];
        }
        current->isLast=true;
    }

    int countWords(string word){
        char c ;
        int n =word.length();
        int counting=0;
        TrieNode* current=this;
        for(int i=0;i<n;i++){
            c=word[i];
            if((current->children).find(c)==current->children.end()){
                return 0;
            }
            counting=(current->childrenCount)[c];
            current=(current->children)[c];
        }
        return counting;
    }
};

int main(){
    TrieNode* root;
    int n ;
    string type,x;
    cin>>n;
    root = new TrieNode();
    for(int i=0;i<n;i++){
        cin>>type>>x;
        if(type=="add"){
            root->insertWord(x);
        }else{
            cout<<root->countWords(x)<<endl;
        }
    }
    return 0;
}