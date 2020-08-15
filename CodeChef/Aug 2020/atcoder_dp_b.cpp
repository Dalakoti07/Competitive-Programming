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
	int n,k;
    cin>>n>>k;
    vi arr(n),dp(n);
    FOR(i,n)
        cin>>arr[i];
    // fill the base cases for last k array
    dp[n-1]=0;
    for(int i=n-2;i>=0;i--){
        int Min=INT_MAX;
        int count=0;
        for(int j=i+1;j<n and count<k;j++){
            Min=min(Min,dp[j]+abs(arr[i]-arr[j]));
            count++;
        }
        dp[i]=Min;
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