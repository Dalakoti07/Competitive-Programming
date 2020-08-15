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
	int n;
    cin>>n;
    vi arr(n),dp(n);
    FOR(i,n)
        cin>>arr[i];
    dp[n-1]=0;
    dp[n-2]=abs(arr[n-1]-arr[n-2]);
    for(int i=n-3;i>=0;i--){
        dp[i]=min(dp[i+1]+abs(arr[i]-arr[i+1]),dp[i+2]+abs(arr[i]-arr[i+2]));
    }
    cout<<dp[0]<<endl;
}

int main(){
    int t=1;
    // cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}