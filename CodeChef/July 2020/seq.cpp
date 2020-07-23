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
	int k;
    cin>>k;
    int bs[k],cs[k];
    FOR(i,k)
        cin>>bs[i];
    FOR(i,k)
        cin>>cs[i];
    int n;
    cin>>n;
    int dp[n];
    for(int i=0;i<k;i++)
        dp[i]=bs[i];
    for(int i=k;i<n;i++){
        dp[i]=0;
        for(int j=i-1,x=0;j>=i-1-k;j--,x++){
            dp[i]+=cs[x]*dp[i-x-1];
        }
    }
    cout<<dp[n-1]<<endl;
}   

int main(){
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}