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
#define INF 1000000000000
using namespace std;

void init(){
  FASTIO;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

ll cntbit(ll n){
    ll cnt=0;
    while(n){
        cnt+=1;
        n/=2;
    }
    return cnt;
}
ll pw2[35];

void preCompute(){
    pw2[0]=1;
    for(ll i=1;i<=34;i++){
        pw2[i] = pw2[i-1]*2;
    }

}

int solve(){

	ll n;
    cin>>n;
    
    ll a[n];
    
    vector<ll> max_bit(32,0) , min_bit(32,INF);
    
    for(ll i=0;i<n;i++){
        cin>>a[i];
        
        ll len = cntbit(a[i]);
        
        max_bit[len] = max( max_bit[len] , a[i]);
        
        min_bit[len] = min( min_bit[len] , a[i]);
    }
    
    ll ans = -1;
    
    for(ll i=1;i<32;i++){
        for(ll j=1;j<32;j++){
            ll X = max_bit[i];
            ll Y = min_bit[j];
            if(X==0 or Y==INF)
                continue;
            else{
                    //X * (2^m-1) - Y * (2^n - 1) m is len of Y n is len of X                    
                    ll diff = (X * (pw2[j]-1)) - (Y * (pw2[i]-1));
                    ans = max(ans,diff);
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    FASTIO;
    int t;
    preCompute();
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}