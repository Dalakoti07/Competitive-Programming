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
void initDS(vector<int>& parents,int n){
    for(int i=1;i<=n;i++)
        parents[i]=i;
}

int findElem(vector<int>& parents,int x){
    if(parents[x]==x)
        return x;
    else{
        parents[x]=findElem(parents,parents[x]);
        return parents[x];
    } 
}

void unionThem(vector<int>& rank, vector<int>& parents,int a,int b){
    int p1=findElem(parents,a);
    int p2 =findElem(parents,b);
    if(p1==p2){
        //cout<<"Invalid query!\n";
        return;
    }
    if(rank[p1-1]>rank[p2-1]){
        parents[p2]=p1;
    }else
        parents[p1]=p2;
}

int solve(){
	int n;
    cin>>n;
    vi arr(n);
    FOR(i,n)
        cin>>arr[i];
    vector<int> parents(n+1);
    initDS(parents,n);
    int q;
    cin>>q;
    int t,a,b;
    while(q--){
        cin>>t;
        if(t==0){
            cin>>a>>b;
            int p1=findElem(parents,a);
            int p2 =findElem(parents,b);
            if(p1==p2){
                cout<<"Invalid query!\n";
                // return;
            }
            if(arr[p1-1]==arr[p2-1]) //draw
                continue;
            unionThem(arr,parents,a,b);
        }else{
            cin>>a;
            cout<<arr[findElem(parents,a)-1]<<endl;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}