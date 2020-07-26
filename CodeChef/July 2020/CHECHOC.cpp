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


int solve(){
	ll n,m,x,y;
    cin>>n>>m>>x>>y;
    // greedy place the max possible at 
    ll sum=0,a,b;
    if(n==1 and m==1){
        cout<<x<<endl;
        return 0;
    }
    if(y<x){
        a=y;
        b=0;
    }else{
        a=x;
        b=min(y-x,x);
    }
    if(a<b)
        swap(a,b);
    ll val=a;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            sum+=val;
            // cout<<val<<" ";
            if(val==a)
                val=b;
            else
                val=a;
        }
        if(m%2==0){
            if(val==a)
                val=b;
            else
                val=a;
        }
        // cout<<endl;
    }
    // cout<<" ans :\n";
    cout<<sum<<endl;
}

int main(){
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}