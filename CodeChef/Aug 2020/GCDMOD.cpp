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
ll powerExponentiation(ll x,ll y,ll mod=MOD){
    ll res=1;
    while(y){
        if(y&1)
            res= ((__int128)res*x)%mod;
        y=y>>1;
        x=((__int128)x*x)%mod;
    }
    return res;
}


void solve(){
	ll a,b,n;
    cin>>a>>b>>n;

    if(a==b){
        cout<<powerExponentiation(a,n)+powerExponentiation(b,n)<<endl;
    }else{
        cout<<__gcd((powerExponentiation(a,n,a-b)+powerExponentiation(b,n,a-b))%(a-b),a-b)<<endl;
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