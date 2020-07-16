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
	ll n,count=0;
    cin>>n;
    string str;
    cin>>str;
    ll suffix[n];
    suffix[n-1]=str[n-1]=='1';
    count=str[n-1]=='1';
    for(ll i=n-2;i>=0;i--){
        suffix[i]= suffix[i+1];
        if(str[i]=='1'){
            count++;
            suffix[i]++;
        }
    }
    for(ll i=0;i<n;i++){
        if(str[i]=='1'){
            count+=suffix[i]-1;
        }
    }
    cout<<count<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}