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
	int n,m;
    cin>>n>>m;
    char arr[n][m];
    FOR(i,n)
        FOR(j,m)
            cin>>arr[i][j];
    int dp[n][m];
    memset(dp,0,sizeof(dp));

    // dp[i][j] denotes no. of ways to go from i,j to n,m

    // fill the last row with 1 and last col with 1
    for(int i=m-1;i>=0 and arr[n-1][i]!='#';i--)
        dp[n-1][i]=1;
    for(int i=n-1;i>=0 and arr[i][m-1]!='#';i--)
        dp[i][m-1]=1;
    // fill the remaining dp array
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            if(arr[i][j]!='#'){
                dp[i][j]=((ll)dp[i+1][j]+(ll)dp[i][j+1])%MOD;
            }
        }
    }
    
    cout<<dp[0][0]<<endl;
}

int main(){
    int t=1;
    // cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}
