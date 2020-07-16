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
	ll particles,limit,chambers;
    cin>>particles>>limit>>chambers;
    ll remaining;
    vector<int> ans;
    for(int i=0;i<chambers;i++){
        remaining=particles%(limit+1);
        particles-= remaining;
        ans.push_back(remaining);
        particles/=(limit+1);
    }
    for(int i: ans)
        cout<<i<<" ";
    cout<<endl;
}

int main(){
    int t=1;
    while(t--){
        solve();
    }
}