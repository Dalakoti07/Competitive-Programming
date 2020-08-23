#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define MOD 1000000007

using namespace std;

void init(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

// code from below

void solve(){
	int n,m,c;
    cin>>n>>m>>c;

    vi arr1(n),arr2(m);
    map<int,int> m1,m2,m3;
    FOR(i,n){
        cin>>arr1[i];
        m1[arr1[i]]++;
    }
    FOR(i,n){
        cin>>arr2[i];
        m2[arr2[i]]++;
    }
    vi dp(c+1);
    // find the max freq 
    for(auto m:m1){
        m3[m.first]=max(m.second,m2[m.first]);
    }
    for(auto m:m2){
        m3[m.first]=max(m.second,m1[m.first]);
    }

    for(int )
}

int main(){
    int t=1;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}