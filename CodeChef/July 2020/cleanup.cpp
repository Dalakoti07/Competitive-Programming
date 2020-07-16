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

// print vector
// print vector of pair int
// print hashmap

int solve(){
    int n,m,x;
    cin>>n>>m;
    set<int> done;
    FOR(i,m){
      cin>>x;
      done.insert(x);
    }
    vi chef,ass;
    bool turnOfChef=true;
    for(int i=1;i<=n;i++){
        if(done.find(i)==done.end()){
            if(turnOfChef)
                chef.pb(i);
            else
                ass.pb(i);
            turnOfChef=!turnOfChef;
        }
    }

    for(int i:chef)
        cout<<i<<" ";
    cout<<endl;
    for(int i:ass)
        cout<<i<<" ";
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}