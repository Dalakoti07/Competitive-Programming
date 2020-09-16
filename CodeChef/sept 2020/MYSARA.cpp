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
const int mxN=5e4;
int arr[mxN];
void solve(){
    const int MOD=(int)1e9 + 7;
	int n;
    cin>>n;
    FOR(i,n)
        cin>>arr[i];
    int count=0;

    //check that b[i] is subset of b[i+1]
    for(int i=0;i<n-1;i++){
        if((arr[i]&arr[i+1])!=arr[i]){
            cout<<0<<endl;
            return;
        }
    }
    // find set bits
    for(int i=0;i<n-1;i++){
        count+=__builtin_popcount(arr[i]);
    }
    // deb(count);
    ll ans=1;
    for(int i=1;i<=count;i++)
        ans=(ans*2 )%MOD;
    cout<<ans<<endl;
}

int main(){
    int t=1;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}