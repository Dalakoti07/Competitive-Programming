#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define MOD 1000003

using namespace std;

void init(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

// code from below

void solve(){
	int n,l,r;
    cin>>n>>l>>r;
    int dp[2][n+1];
    // memset(dp,1,sizeof(dp));
    for(int i=0;i<2;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=1;
    
    bool secondRow=true;

    for(int i=1;i<(r-l)+1;i++){
        if(secondRow){
            for(int j=1;j<=n;j++)
                dp[1][j]=(dp[0][j] + dp[1][j-1])%MOD;
            secondRow=false;
        }
        else{
            for(int j=1;j<=n;j++)
                dp[0][j]=(dp[1][j] + dp[0][j-1])%MOD;
            secondRow=true;
        }
    }
    int sum=0;

    // dp array
    // for(int i=0;i<2;i++,cout<<endl)
    //     for(int j=0;j<=n;j++)
    //         cout<<dp[i][j]<<" ";
    int idx;
    if((r-l+1)%2)
        idx=0;
    else
        idx=1;
    for(int i=1;i<=n;i++)
        sum=(sum+dp[idx][i])%MOD;
    cout<<sum<<endl;
}

int main(){
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}