#include  <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, LOGN = 22;
// 2^20 = 1e6

vector<int> adj[N];

int A[N], h[N];
int p[N][LOGN];
int val[N][LOGN];// val[u][i] = XOR of the path from node u to its (2^i - 1)_th parent.

pair<int, int> lca(int u, int v) {// {lca of (u, v), xor of the path from u to v}
    if(h[u] < h[v]) swap(u, v);
    // for sure h[u] >= h[v]
    // Step 1 - kill the difference, and make them same height
    int diff = h[u] - h[v];
    int ans = 0;
    // whenever you make a jump using p[][] array, update the  ans also.
    //cout<<"u: "<<u<<" v: "<<v<<" ans: "<<ans<<endl;
    for(int i = 0; i < LOGN; i++) {// Reversing this loop works
        if((diff & (1 << i)) != 0) { // if diff has i_th bit on then
            ans = ans ^ val[u][i];
            u = p[u][i];
        }
    }
    // Conjecture here that u and v have same height
    // ans uptill here does not inclue the last value
    if(u == v)  return {u, ans ^ A[u]};
    // Step 2 - At same height, start going from higher powers of 2 to lower powers of 2
    // Make the jump, if the ancestors mismatch
    for(int i = LOGN - 1; i >= 0; i--) { // 32 -> 16-> ... // Reversing this loop will NOT work
        if(p[u][i] != p[v][i]) { // 2^ith par of u != 2^ith par of v
            ans = ans ^ val[u][i] ^ val[v][i];
            u = p[u][i]; // then make u climb there
            v = p[v][i]; // make v climb there
            // height = 20, i = 5, 2^5 = 32th parents will match
            // then 16th parents wont match
        }
    }
    // Conjecture = we will be 1 step away from the LCA
    // LCA has not been included in ans till now.
    int lca_node = p[u][0];
    ans = ans ^ val[u][0] ^ val[v][0] ^ A[lca_node];
    //cout<<"u: "<<u<<" v: "<<v<<" ans: "<<ans<<endl;
    return {lca_node, ans};
}

void dfs(int u, int prv) {
    h[u] = h[prv] + 1;
    p[u][0] = prv;
    val[u][0] = A[u];

    for(auto v : adj[u]) {
        if(v == prv)    continue;
        dfs(v, u);
    }
}

void solve() {
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
        val[0][i] = 0; // identify function for XOR
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
        //cout<<"DBG ->" <<x.first<<" "<<x.second<<endl;
        cout<<x.second<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)  solve();
}
