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

vector<ll> nodeSum(4*((int)1e5 + 1)),lazyAdd(4*((int)1e5 + 1)),lazyMul(4*((int)1e5 + 1));

// refer editorial for approach 
// https://cp-algorithms.com/data_structures/segment_tree.html for code
// seg tree
void buildTree(vector<int>& arr,int idx,int l,int r){
    if(l>r) return;
    if(l==r)
        nodeSum[idx]=arr[l];
    int mid =l- ((l-r)/2);
    buildTree(arr,idx*2,l,mid);
    buildTree(arr,idx*2+1,mid+1,r);
    nodeSum[idx]=((nodeSum[idx*2])%MOD+(nodeSum[idx*2 + 1])%MOD)%MOD;
}

void push(int idx){
    nodeSum[idx*2] = nodeSum[idx]*lazyMul[idx] + lazyAdd[]*(r-l+1);
    lazy[idx*2] += lazy[idx];
    nodeSum[idx*2+1] += lazy[idx];
    lazy[idx*2+1] += lazy[idx];
    lazy[idx] = 0;
}

void updateTree(vector<int>& arr,int x,int y,int mul,int add,int idx,int l,int r){
    if(l>r) return;
    if(l==x and r==y){
        push(idx);
        lazyAdd[idx*2]=add;
        lazyMul[idx*2]=mul;
        nodeSum[idx]=nodeSum[idx]*mul + add*(r-l+1);
    }else{
        push(idx);
        int mid = x-((x-y)/2);
        updateTree(arr,x,mid,mul,add,idx*2,l,min(mid,r));
        updateTree(arr,mid+1,y,mul,add,idx*2,max(mid+1,l),r);
    }
}
int queryTree(int x,int y,int idx,int l,int r){
    if(l>r) return 0;
    if(l==x and r==y)
        return tree[idx];
    push(idx);

}

int solve(){
    int n,q;
    cin>>n>>q;
    vi arr(n+1);
    FORE(i,1,n)
        cin>>arr[i];
    buildTree(arr,1,1,n);
    while(q--){
        int type,x,y,v;
        cin>>type;
        if(type==1){
            cin>>x>>y>>v;
            // add
            // only one type of update 
            // if adding x to all elem that means mul by 1 and then add x
            updateTree(arr,x,y,1,v,1,1,n);
        }else if(type==2){
            cin>>x>>y>>v;
            // mul
            // if mul x to all elem that means mul by x and then add 0
            updateTree(arr,x,y,v,0,1,1,n);
        }else if(type==3){
            cin>>x>>y>>v;
            // if changing all elem to x means mul by 0 and then add x
            updateTree(arr,x,y,0,v,1,1,n);
        }else{
            cin>>x>>y;
            cout<<queryTree(x,y,1,1,n);
        }
    }
}

int main(){
    int t=1;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}