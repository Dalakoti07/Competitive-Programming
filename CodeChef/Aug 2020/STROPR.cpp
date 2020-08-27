#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define MOD 1e9+7

using namespace std;

void init(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

// code from below
const int maxn=1e5 +1;
int arr[maxn];

void solve(){
	int n,x;
    ll m;
    cin>>n>>x>>m;
    FOR(i,n)
        cin>>arr[i];
    for(int i=1;i<=m;i++){
        for(int i=1;i<n;i++)
            arr[i]= ((ll)arr[i] + (ll)arr[i-1])%MOD;
    }
    cout<<arr[x-1]<<endl;
}

int main(){
    FASTIO;
    int t=1;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}