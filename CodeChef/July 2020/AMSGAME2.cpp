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

ll dp[62][10002];
ll arr[62];
int totalCalls=0;
ll countAllSubs(ll currentGcd,ll elemVisted,ll n){
    totalCalls++;
    if(elemVisted==n){
        if(currentGcd==1){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[elemVisted][currentGcd]!=-1){
        return dp[elemVisted][currentGcd];
    }
    dp[elemVisted][currentGcd]= countAllSubs(__gcd(arr[elemVisted],currentGcd),elemVisted+1,n) 
    + countAllSubs(currentGcd,elemVisted+1,n);
    return dp[elemVisted][currentGcd];
}

// one thing is repeated again and again that sequence does not matter in subsequence lets take advantage of that
void solve(){
    for(ll i=0;i<62;i++)
        for(ll j=0;j<10002;j++)
            dp[i][j]=-1;
    ll n;
    cin>>n;
    // vi arr(n);
    FOR(i,n)
        cin>>arr[i];
    ll count=0,x;
    FOR(i,n){
        totalCalls=0;
        x=countAllSubs(arr[i],i+1,n);
        // cout<<" subset explored for i: "<<totalCalls<<endl;
        count+=x;
    }
    cout<<count<<endl;
}

int main(){
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}