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
    vector<ll> arr(n),dp(n,0);
    FOR(i,n)
        cin>>arr[i];
    // complexity is n^2, dp[i] denotes min cost going from i to n including both
    /*
    dp[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        ll ans=INT_MAX;
        for(int j=i+1;j<n and ((j-i)<=k and (j-i)>=1);j++){
            ans=min(ans,(dp[j]*arr[i])%MOD);
        }
        dp[i]=ans;
    }
    */
    // sliding window protocol
    vector<ll> score(n,0);
    score[0]=arr[0];
    for(int i=1;i<=min(n,k);i++){
        score[i]=arr[0]*arr[i];
    }
    for(int i=k+1;i<n;i++){
        // sort the just behind window
        sort(arr.begin()+i-k-1,arr.begin()+i);
        score[i]=(arr[i]*score[i-k]);
    }
    cout<< score[n-1]<<endl;
}

int main(){
    int t=1;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}