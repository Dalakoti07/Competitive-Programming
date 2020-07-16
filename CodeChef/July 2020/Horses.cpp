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
    int n;
    cin>>n;
    vector<int> horses(n);
    FOR(i,n)
        cin>>horses[i];
    sort(horses.begin(),horses.end());
    int minDiff=INT_MAX;
    for(int i=1;i<n;i++){
        minDiff=min(minDiff,horses[i]-horses[i-1]);
    }
    cout<<minDiff<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}