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
    string stones,jwels;
    cin>>stones>>jwels;
    multiset<char> set1,set2;
    for(int i=0;i<stones.size();i++)
        set1.insert(stones[i]);
    for(int i=0;i<jwels.size();i++)
        set2.insert(jwels[i]);
    int count=0;
    for(char c: set2){
        auto itr=set1.find(c);
        if(itr!=set1.end()){
            count++;
            // set1.erase(itr);
        }
    }
    cout<<count<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}