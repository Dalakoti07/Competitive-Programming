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
    vector<ll> arr(n);
    FOR(i,n){
        cin>>arr[i];
    }
    vector<ll> dp(n);
    dp[0]=1;
    ll sum=dp[0];
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1])
            dp[i]=dp[i-1]+2;
        else
            dp[i]=1+dp[i-1];
        sum+=dp[i];
    }
    cout<< dp[n-1]<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}