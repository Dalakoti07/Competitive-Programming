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


// make as many as global var
// fastio with cin and cout is faster than scanf and printf

int size=0;
vector<int> adj[((int)1e5) + 1];
bool visited[(int)1e5 + 1];

int allVisited(int n){
    for(int i=1;i<n;i++)
        if(visited[i]==false) return i;
    return -1;
}

void dfs(int i){
    // cout<<"exploring "<<i<<" and it has "<<adj[i].size()<<" children \n";
    size++;
    visited[i]=true;
    for(int j=0;j<adj[i].size();j++){
        if(visited[adj[i][j]]==false)
            dfs(adj[i][j]);
    }
}

void solve(){
	// clear graph
    for(int i=0;i<=(int)1e5;i++)
        adj[i].clear();
    int n,m,a,b;
    cin>>n>>m;
    FOR(i,m){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    if(m==0){
        cout<<n<<" "<<1<<endl;
        return;
    }
    // dfs and count components
    int componentsCount=0,nodesSoFar=0;
    ll product=1;
    memset(visited,false,sizeof(visited));
    int nextNode=1;
    for(int i=1;i<=n;i++){
        if(visited[i]==false){
            size=0;
            componentsCount++;
            dfs(i);

            // count the nodes covered 
            product= (product * (ll)size)%MOD;
        }
    }
    cout<<componentsCount<<" "<<product<<endl;
}

int main(){
    int t;
   cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}