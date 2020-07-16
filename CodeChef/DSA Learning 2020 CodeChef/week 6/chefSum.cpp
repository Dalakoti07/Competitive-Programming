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
    ll sumOfAllEleme=0,ans=INT_MAX,idx;
    ll n;
    cin>>n;
    vi arr(n),prefixSum(n),suffixSum(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]<ans){
            idx=i+1;
            ans=arr[i];
        }
    }

    /*
    // problem can be reduced as idx of minimum
    prefixSum[0]=arr[0];
    suffixSum[0]=sumOfAllEleme;
    ans=prefixSum[0]+suffixSum[0];
    idx=1;
    for(ll i=1;i<=n-1;i++){
        prefixSum[i]=prefixSum[i-1]+arr[i];
        suffixSum[i]=sumOfAllEleme-prefixSum[i-1];
        if(prefixSum[i]+suffixSum[i] < ans){
            ans=prefixSum[i]+suffixSum[i];
            idx=i+1;
        }
    }
    */
    cout<<idx<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}