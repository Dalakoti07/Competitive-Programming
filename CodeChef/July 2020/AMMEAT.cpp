#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
	ull n,k;
    cin>>n>>k;
    vector<ull> arr(n);
    FOR(i,n)
        cin>>arr[i];
    sort(arr.begin(),arr.end(),greater<ll>());
    // FOR(i,n)
    //     cout<<arr[i]<<" ";
    // cout<<endl;
    ull count=1,soFar=arr[0];
    for(int i=1;i<n;i++){
        if(soFar>=k)
            break;
        soFar+=arr[i];
        count++;        
    }
    if(soFar<k)
        cout<<-1<<endl;
    else 
        cout<<count<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}