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
	ll n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    ll maxy=INT_MIN;
    FOR(i,n){
        cin>>arr[i];
        maxy=max(maxy,arr[i]);
    }
    vector<ll> afterOneOperation(n),afterSecondOperation(n);
    ll maxAfterFirst=INT_MIN;
    FOR(i,n){
        afterOneOperation[i]=maxy-arr[i];
        maxAfterFirst=max(afterOneOperation[i],maxAfterFirst);
    }
    FOR(i,n){
        afterSecondOperation[i]=maxAfterFirst-afterOneOperation[i];
    }
    if(k==0){
        FOR(i,n)
            cout<<arr[i]<<" ";
    }
    else if(k%2){
        FOR(i,n)
            cout<<afterOneOperation[i]<<" ";
    }else{
        FOR(i,n)
            cout<<afterSecondOperation[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t=1;
    while(t--){
        solve();
    }
}