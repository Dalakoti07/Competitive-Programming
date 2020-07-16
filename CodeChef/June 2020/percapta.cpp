#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back

using namespace std;

void init(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

// print vector
// print vector of pair int
// print hashmap

void dfs(int i,vector<int> graph[],vector<bool>& nodeStatus,int n,vector<int>& pathFromThisNode){
    pathFromThisNode.pb(i);
    nodeStatus[i]=false;
    for(int j=0;j<graph[i].size();j++){
        if(nodeStatus[graph[i][j]]){
            dfs(graph[i][j],graph,nodeStatus,n,pathFromThisNode);
        }
    }
}

int solve(){
    int n,m,temp;
    cin>>n>>m;
    vector<float> percaptaIncome(n);
    vector<int> income(n);
    for(int i=0;i<n;i++)
        cin>>income[i];
    float maxPerCaptaIncome=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>temp;
        percaptaIncome[i]=(income[i]*1.0)/(temp*1.0);
        maxPerCaptaIncome=max(percaptaIncome[i],maxPerCaptaIncome);
    }
    // no take only those nodes which have percapta income equal to max per capta
    // adjency list
    vector<int> graph[n];
    vector<bool> nodeStatus(n,false);// contains if node is in graph of not , false means not in graph
    for(int i=0;i<n;i++)
        if(percaptaIncome[i]==maxPerCaptaIncome)
            nodeStatus[i]=true;

    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        if(nodeStatus[a-1] and nodeStatus[b-1]){
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }
    }
    vector<int> maxPath;
    for(int i=0;i<n;i++){
        if(nodeStatus[i]){
            vector<int> pathFromThisNode;
            dfs(i,graph,nodeStatus,n,pathFromThisNode);
            if(pathFromThisNode.size()>maxPath.size()){
                // maxPath.clear();
                // maxPath(pathFromThisNode.begin(),pathFromThisNode.end());
                maxPath=pathFromThisNode;
            }
        }
    }
    cout<<maxPath.size()<<endl;
    for(int i=0;i<maxPath.size();i++)
        cout<<maxPath[i]+1<<" ";
    cout<<endl;
}

int main(){
    FASTIO;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}