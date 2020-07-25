#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define MOD 1000000007

using namespace std;

void init(){
  FASTIO;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

class Node{
public:
    map<char,Node*> childrens;
    int priority;
    bool isLast;
    int index;
    Node(int p,int i){
        this->priority=p;
        this->index=i;
        this->isLast=false;
    }
};

Node* root= new Node(0,0);

void insertIntoTrie(Node* root,string s,int p,int idx){
    char c;
    int n =s.length();
    Node* currentNode=root;
    for(int i=0;i<n;i++){
        c=s[i];
        if(currentNode->childrens.count(c)==0){
            currentNode->childrens[c]= new Node(p,idx);
        }else{
            // update priority if necessary
            if(currentNode->childrens[c]->priority<p){
                currentNode->childrens[c]->priority=p;
                currentNode->childrens[c]->index=idx;
            }
        }
        if(i==n-1)
            currentNode->childrens[c]->isLast=true;
        currentNode=currentNode->childrens[c];
    }
}

int readString(Node* root,vector<string>& all,int idx){
	string s;
    int p;
    cin>>s>>p;
    all.pb(s);

    // insert into trie
    insertIntoTrie(root,s,p,idx);
}

void getBestDish(vector<string>& dishes,Node* root,string s){
    char c;
    int n =s.length();
    Node* currentNode=root;
    int ans=0;
    for(int i=0;i<n;i++){
        c=s[i];
        if(currentNode->childrens.count(c)==0){
            cout<<"NO\n";
            return;
        }
        ans=currentNode->childrens[c]->index;
        currentNode=currentNode->childrens[c];
    }
    cout<<dishes[ans]<<endl;
}

int main(){
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    string s;
    vector<string> all;
    int p;
    cin>>s>>p;
    all.pb(s);
    root->priority=p;
    root->index=0;
    insertIntoTrie(root,s,p,0);
    t--;
    int i=1;
    while(t--){
        readString(root,all,i);
        i++;
    }
    int q;
    cin>>q;
    while(q--){
        cin>>s;
        getBestDish(all,root,s);
    }
}