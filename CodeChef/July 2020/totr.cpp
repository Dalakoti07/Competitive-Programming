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

int solve(){
    int n;
    cin>>n;
    string conversion;
    cin>>conversion;
    vector<char> alphabets(26);
    for(int i=0;i<26;i++)
        alphabets[i]=conversion[i];
    
    string query;
    while(n--){
        cin>>query;
        for(int i=0;i<query.length();i++){
            if(query[i]=='_')
                cout<<" ";
            else if(query[i]=='!' or query[i]=='.' or query[i]==',' or query[i]=='?')
                cout<<query[i];
            else if(query[i]<='Z'){
                cout<<(char) (alphabets[query[i]-'A']-32);
            }else{
                cout<< alphabets[query[i]-'a'];
            }
        }
        cout<<endl;
    }
}

int main(){
    int t=1;
    while(t--){
        solve();
    }
}