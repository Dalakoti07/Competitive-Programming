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
    vector<int> arr(n);
    ll maxR=INT_MIN;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    maxR=arr[0]+arr[n-1]+arr[1];
    for(int i=1;i<n;i++){
        maxR=max(maxR,(long long) arr[i]+arr[i-1]+arr[(i+1)%n]);
    }
    cout<<maxR<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}