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
	ll n,k;
    cin>>n>>k;
    vi arr(n);
    FOR(i,n)
        cin>>arr[i];
    ll count=0,pck,curr=0;
    for(int i=0;i<n;i++){
        pck=((arr[i]-curr)/k) + ((arr[i]-curr)%k>0) ;
        // cout<<" at i package is :"<< (arr[i]-curr)/k<<" + "<<((arr[i]-curr)%k>0) <<" = "<<pck<<endl;
        count+=pck;
        // cout<<" at i: "<<i<<" and count: "<<count<<endl;
        curr+=pck*k - arr[i];
        if(curr>0)
            curr--;
    }
    // cout<<"\nans is ";
    cout<<count<<endl;
}

int main(){
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}