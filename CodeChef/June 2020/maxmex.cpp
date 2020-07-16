#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back

using namespace std;

void init(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

// print vector
// print vector of pair int
// print hashmap

int solve(){
    int n,k,count=0,x;
    cin>>n>>k;
    set<int> arr;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x!=k){
            count++;
            arr.insert(x);
        }
    }
    int actualMex=1;
    while(arr.count(actualMex))
        actualMex++;
    if(actualMex==k)
        cout<<count<<endl;
    else
        cout<<-1<<endl;
}

int main(){
    FASTIO;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}