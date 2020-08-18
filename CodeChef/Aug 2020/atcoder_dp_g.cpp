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
int dp[(int)1e5+1]; // dp[i] would store the max path length from node i of the tree
vector<int> adj[(int)1e5 + 1];
bool visited[(int)1e5+1];
void dfs(int i){
    dp[i]=0;
    visited[i]=true;
    for(int child :adj[i]){
        if(!visited[child])
            dfs(child);
        dp[i]=max(1+dp[child],dp[i]);
    }
}
void solve(){
	for(int i=0;i<=(int)1e5;i++)
        adj[i].clear();
    memset(visited,false,sizeof(visited));
    memset(dp,0,sizeof(dp));

    int n,m,a,b;
    cin>>n>>m;
    FOR(i,m){
        cin>>a>>b;
        adj[a].pb(b);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i])
            dfs(i);
    }
    int Max=INT_MIN;
    for(int i=1;i<=n;i++){
        Max=max(Max,dp[i]);
    }
    cout<<Max<<"\n";
}

int main(){
    int t=1;
    // cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}