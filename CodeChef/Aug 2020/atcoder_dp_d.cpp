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
ll dp[101][(int)1e5 + 1];

void solve(){
	int n,maxWeight;
    cin>>n>>maxWeight;
    vi values(n+1),weights(n+1);
    for(int i=1;i<=n;i++)
        cin>>weights[i]>>values[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=maxWeight;j++){
            if(j-weights[i]>=0)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weights[i]]+values[i]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }

    // cout<<" dp array is \n";
    // for(int i=0;i<=n;i++,cout<<endl)
    //     for(int j=0;j<=maxWeight;j++)
    //         cout<<dp[i][j]<<" ";

    cout<<dp[n][maxWeight]<<endl;
}

int main(){
    int t=1;
    // cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}