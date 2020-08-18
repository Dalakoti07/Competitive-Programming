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
    vector<ll> arr(n);
    FOR(i,n)
        cin>>arr[i];
    vector<vector<ll>> dp(k+1,vector<ll>(n));
    // memset(dp,0,sizeof(dp));
    // dp[i][j] tells ways to distribute all i candies to j students, so that no candies are left and each student 
    // get [0,ai] candies

    // we have maintained a prefix array to calculate dp[][] in O(1)

    // put the base cases, 1st row is 1
    for(int i=0;i<n;i++)
        dp[0][i]=1;
    // base case first col is 
    for(int i=1;i<=arr[0];i++)
        dp[i][0]=1;

    // fill the remaining dp
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            if(j>arr[i]){
                dp[j][i]=dp[j][i-1];
            }else{
                dp[j][i]=dp[j][i-1] + dp[j-1][i-arr[i]-1];
            }
        }
    }
    
    cout<<"dp array is \n";
    for(int i=0;i<=k;i++,cout<<endl)
        for(int j=0;j<n;j++)
            cout<<dp[i][j]<<" ";
}

int main(){
    int t=1;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}