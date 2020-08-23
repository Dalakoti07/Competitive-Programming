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
	int n, a, b;
    scanf ( "%d%d%d", &n, &a, &b );
    if ( !( n & 1 ) && abs( a - b ) == n / 2 ) 
        puts( "0" );
    else 
        printf( "%d\n", min( abs( a - b ) - 1, min( a, b ) - 1 + n - max( a, b ) ) );
}

int main(){
    int t=1;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}