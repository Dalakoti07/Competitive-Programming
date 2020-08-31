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

void solve(){
	int n,x;
    cin>>n;
    map<int,int> mappy;
    FOR(i,n){
        cin>>x;
        mappy[x]++;
    }
    int nesVal=-1,nesKey=-1;
    map<int,int> freqMap;
    for(auto m:mappy){
        freqMap[m.second]++;
    }
    for(auto m:freqMap){
        // cout<<"key: "<<m.first<<" val: "<<m.second<<endl;
        if(m.second>nesVal){
            nesVal=m.second;
            nesKey=m.first;
        }
    }
    cout<<nesKey<<endl;
}

int main(){
    int t=1;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}