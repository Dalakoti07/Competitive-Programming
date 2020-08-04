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
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

// code from below

void solve(){
	string a,b,query;
    cin>>a>>b;
    int q;
    cin>>q;
    if(a.size()!=b.size()){
        FOR(i,q){
            cin>>query;
        }
        cout<<"NO\n";
    }else{
        bool graph[26][26]={false};
        
        FOR(i,q){
            cin>>query;
            char first,second;
            first=query[0];
            second=query[3];
            graph[first-'a'][second-'a']=true;
        }
        
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(graph[i][k] and graph[k][j])
                        graph[i][j]=1;
                }
            }
        }
        int i=0,bound=a.size();
        for(;i<bound;i++){
            if((graph[a[i]-'a'][b[i]-'a']==false) and a[i]!=b[i])
                break;
        }
        
        if(i!=bound){
            cout<<"NO\n";
        }else
            cout<<"YES\n";
    }
}

int main(){
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}