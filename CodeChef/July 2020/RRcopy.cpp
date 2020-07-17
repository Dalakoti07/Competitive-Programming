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

// it was never told in question that elemens are unique

int solve(){
	int n,x;
    cin>>n;
    map<int,bool> mappy;
    for(int i=0;i<n;i++){
        cin>>x;
        mappy[x]=true;
    }
    cout<<mappy.size()<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}