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

// print vector
// print vector of pair int
// print hashmap

int solve(){
	ll n,k,ans;
    cin>>n>>k>>ans;
    vector<ll> arr(n);
    FOR(i,n)
        cin>>arr[i];
    string op;
    cin>>op;
    if(k!=0){
        if(op=="AND"){
            FOR(i,n){
                ans=ans&arr[i];
            }
        }else if(op=="OR"){
            FOR(i,n){
                ans=ans|arr[i];
            }
        }else{
            if(k%2)
            FOR(i,n){
                ans=ans^arr[i];
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}