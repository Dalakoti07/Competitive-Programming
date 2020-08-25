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
	int n,x,y;
    cin>>n;
    FOR(i,n)
        cin>>x>>y;
    // for n=1,2,3,4,5 answer is 0
    // use pen and paper you will find that polygon of side n has child polygon with side as n/2 (integer division ) 
    int answer=n;
    while(n>5){
        n/=2;
        answer+=n;
    }
    cout<<answer<<endl;
}

int main(){
    int t=1;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}