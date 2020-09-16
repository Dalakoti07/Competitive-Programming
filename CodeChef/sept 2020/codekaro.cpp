#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define deb(x) cout<< #x << " = "<<x<<endl;

using namespace std;

void init(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

// code from below
const ll MOD=1e9+7;
#define modinv(n,m) modex(n,m-2,m)
#define moddiv(n,d,m) (n*modinv(d,m))%m

ll modex(ll x,ll p,ll m){
    ll ans=1;
    x=x%m;
    while(p>0)
    {
        if(p&1) ans=(ans*x)%m;
        p=p>>1;
        x=(x*x)%m;
    }
    return ans;
}

void solve(){
	ll n,k,l,num,deno;
    cin>>n>>k;
    k<<=1;
    while(n--){
        cin>>l;
        num=modex(52+k,l>>1,MOD);
        deno=modex(52,l-(l&1),MOD);
        cout<<moddiv(num,deno,MOD)<<endl;
    }
}

int main(){
    int t=1;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}