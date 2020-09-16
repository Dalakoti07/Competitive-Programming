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
ll BinaryExponentiation(ll a,ll b,ll mod){
    long res=1;
    while(b>0){
        if(b%2==1) res = (res * a)%mod;
        a=(a*a)%mod;
        b=b/2;
    }
    return res;
}
void solve(){
    ll MOD =1e9+7;
	int n,m;
    ll ans=1;
    cin>>n>>m;
    vi arr(n+2);
    // arr is freq array which stores the nodes count which are at distance i from node 1
    arr[0]=1;
    for(int i=2;i<=n;i++){
        int pos;
        cin>>pos;
        arr[pos]++;
    }

    // check if no graph possible
    for(int i=1;i<=n;i++){
        if(arr[i]!=0 and arr[i-1]==0){
            cout<<0<<endl; // not possible
            return;
        }else if(arr[i]>0){
            // ways to join layer i and layer i-1
            ans=ans*BinaryExponentiation(arr[i-1],arr[i],MOD);
        }
        ans= ans % MOD;
    }

    // calculate edges which can drawn to make up remaining edges
    ll node_pairs=0;
    for(int i=1;i<n-1;i++){
        ll count=arr[i];
        node_pairs+=((count*(count-1))/2);
    }
    if(m-(n-1)>0){
        m-=(n-1);
        if(m>node_pairs)
            ans=0;
        else{
            ll ways=0,nums=1,deno=1;
            // calculating nodePair C m that is combinations possible
            // we will use inverse MODulo and fermat theorem which make inverse MODulo of deno as deno^(MOD-2)
            // given MOD is prime and as in question MOD 10^9 +7 is prime
            for(ll i=node_pairs-(ll) m +1 ;i<=node_pairs;i++){
                nums*=i;
                nums%=MOD;
            }
            for(int i=1;i<=m;i++){
                deno*=i;
                deno%=MOD;
            }
            ways=nums* BinaryExponentiation(deno,MOD-2,MOD);
            ways%=MOD;
            ans=(ans*ways)%MOD;
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t=1;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}