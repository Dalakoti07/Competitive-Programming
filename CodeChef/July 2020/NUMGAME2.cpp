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

vector<int> primes;
void preCompute(){
    // we cannot make sieve of this size, so there must be another hack, to it might be combinactors problem where 
    // we have to find the pattern
    //if you see all prime numbers except for 2 ,all others fit in either 4n-1 or 4n+1 where n is a positive integer
    
}

int solve(){
	
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}