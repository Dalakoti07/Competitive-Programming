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

int getIdx(char w[],char c ){
    for(int i=0;i<4;i++)
        if(w[i]==c)
            return i;
    return -1;
}

bool fillAptly(string& word,int i,int j,char chefStr[]){
    string coy=word;
    for(int a=i,b=0;a<=j;a++,b++){
        if(coy[a]=='?')
            coy[a]=chefStr[b];
        else{
            if(coy[a]!=chefStr[b])
                return false;
        }
    }
    word=coy;
    // cout<<" and str modified to "<<word<<endl;
    return true;
}

int solve(){
    char chefStr[]="CHEF";
	string word;
    cin>>word;
    int n =word.length();
    for(int i=n-1;i>=0;i--){
        fillAptly(word,i-3,i,chefStr);
    }
    for(int i=0;i<n;i++)
        if(word[i]=='?')
            word[i]='A';
    cout<<word<<endl;
}

int main(){
    // init();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}