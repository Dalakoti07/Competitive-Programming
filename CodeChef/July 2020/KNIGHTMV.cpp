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

bool isValid(string a,string b){
    if(a[0]+2==b[0] and a[1]-1==b[1]){
        // right top
        cout<<"Yes\n";
    }else if(a[0]+2==b[0] and a[1]+1==b[1]){
        // right bottom
        cout<<"Yes\n";
    }else if(a[0]-2==b[0] and a[1]-1==b[1]){
        // left top
        cout<<"Yes\n";
    }else if(a[0]-2==b[0] and a[1]+1==b[1]){
        // left bottom
        cout<<"Yes\n";
    }else if(a[0]-1==b[0] and a[1]-2==b[1]){
        // top left
        cout<<"Yes\n";
    }else if(a[0]+1==b[0] and a[1]-2==b[1]){
        // top right
        cout<<"Yes\n";
    }else if(a[0]-1==b[0] and a[1]+2==b[1]){
        // bottom left
        cout<<"Yes\n";
    }else if(a[0]+1==b[0] and a[1]+2==b[1]){
        // bottom right
        cout<<"Yes\n";
    }else
       cout<<"No\n"; 
}

int solve(){
	string words;
    getline(cin,words);
    if(words.length()!=5){
        cout<<"Error\n";
    }else if(words[0]>='a' and words[0]<='h' and words[1]>='1' and words[1]<='8' and words[2]=='-' 
                and words[3]>='a' and words[3]<='h' and words[4]>='1' and words[4]<='8' ){

        isValid(words.substr(0,2),words.substr(3,2));
    }else{
        cout<<"Error\n";
    }
}

int main(){
    init();
    int t;
    cin>>t;
    cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}