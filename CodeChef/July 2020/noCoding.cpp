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
	string prog;
    cin>>prog;
    int count=1;
    int n =prog.length();
    char lastChar=prog[0];
    count+=2+(prog[0]-'a');
    for(int i=1;i<n;i++){
        if(lastChar!=prog[i])
            count+=2+(prog[i]-'a');
        lastChar=prog[i];
        // cout<<" \nat i: "<<i<<" ans : "<<count<<endl;
    }
    // cout<<"\ncount : "<<count<<"\n";
    if(count<(11*n))
        cout<<"YES\n";
    else
        cout<<"NO\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}