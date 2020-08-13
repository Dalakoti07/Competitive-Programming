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
const int N =1e5 + 5, LOGN =22;
vector<int> adj[N];

int A[N],h[N];
int p[N][LOGN];
int val[N][LOGN];
// val [i][j] contains XOR from i to (a^j - 1)th parent inclusive of both

// u is the Node Id 
void dfs(int u,int par){
    p[u][0]=par;
    h[u]=1+h[par];
    val[u][0]=A[u];
    for(auto i: adj[u]){
        if(i==par) continue;
        dfs(i,u);
    }
}

// it would return {lca id of node, XOR from u to v}
pair<int,int> lca(int u,int v){
    // we will always make u of higher depth for easy implementation
    if(h[u]<h[v]) swap(u,v);

    // kill the difference
    int diff =h[u]-h[v];
    int ans=0;

    for(int i=0;i<LOGN;i++){
        if((diff & ( 1<<i )) !=0 ){
            ans= ans ^ val[u][i];
            u = p[u][i];
        }
    }

    // now we have the same height if we have same node id it means lca is u or v
    if(u==v) return {u,ans^A[u]};

    // binary search for lca
    for(int i=LOGN-1; i>=0 ;i--){
        if(p[u][i] != p[v][i]){
            ans = ans ^ val[u][i] ^ val[v][i];
            // make u and v jump
            u= p[u][i];
            v= p[v][i];
        }
    }

    // now we will have a lca just a one step above
    int lca_node =p[u][0];
    ans = ans ^ val[u][0] ^ val[v][0] ^ A[lca_node];

    return {lca_node,ans}; 
}

void solve(){
	for(int i = 0; i < N; i++) {
        adj[i].clear();
    }
    int n, q, u, v;
    cin>>n>>q;
    for(int i = 1; i <= n; i++) cin>>A[i];
    for(int i = 1; i < n; i++) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for(int i = 0; i < LOGN; i++) {
        p[0][i] = 0;
        val[0][i] = 0; 
        // identify function for XOR
        // val[0][i] = INT_MIN; // identify function for MAX
    }
    for(int i = 1; i < LOGN; i++) {
        for(u = 1; u <= n; u++) {
            p[u][i] = p[p[u][i - 1]][i - 1];
            val[u][i] = val[u][i - 1] ^ val[p[u][i - 1]][i - 1];
            // XOR the first half of the path with the second half of the path.
        }
    }
    while(q--) {
        cin>>u>>v;
        pair<int, int> x = lca(u, v);
        cout<<x.second<<'\n';
    }
}

int main(){
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}