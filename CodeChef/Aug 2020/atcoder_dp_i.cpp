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
double heads[3000],tails[3000];
double ans=0;
int n;
void rec(int i,int h,int t,double curVal){
    if(h+t > n){
        return;
    }
    if(h+t ==n){
        if(h>t){
            ans+=curVal;
            return;
        }else
            return;
    }
    
    rec(i+1,h+1,t,curVal*(double)heads[i+1]);
    rec(i+1,h,t+1,curVal*(double)tails[i+1]);
}
void solve(){
    ans=0;
    double p;
    cin>>n;
    FOR(i,n){
        cin>>p;
        heads[i+1]=p;
        tails[i+1]=1.0-p;
    }
    // rec(0,0,0,1.0);
    double dp[n][n+1];
    memset(dp,0.0,sizeof(dp));
    // base case col 0, will have 1 coin 1 tail, 2 coin and 2 tails, and so on....
    dp[0][0]=tails[1];
    for(int i=1;i<n;i++){
        dp[i][0]=dp[i-1][0]*tails[i+1];
    }
    // filling the first row,
    dp[0][1]=heads[1];

    // dp[i][j] means after taking i coins what would be probability of getting j heads 
    for(int i=1;i<n;i++){
        for(int j=1;j<=i+1;j++){
            dp[i][j]=dp[i-1][j]*tails[i+1] + dp[i-1][j-1]*heads[i+1];
        }
    }

    for(int i=ceil((n+1)/2);i<=n;i++)
        ans+=dp[n-1][i];
    cout<<fixed << setprecision(10)<<ans<<endl;
}

int main(){
    int t=1;
    // cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}