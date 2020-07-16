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

void multiply(ll F[2][2], ll M[2][2]); 
  
void power(ll F[2][2], ll n); 

/* function that returns nth Fibonacci number */
ll fib(ll n){ 
  ll F[2][2] = {{1,1},{1,0}}; 
  if (n == 0) 
    return 0; 
  power(F, n-1); 
  return F[0][0]; 
} 
  
/* Optimized version of power() in method 4 */
void power(ll F[2][2], ll n){ 
  if( n == 0 || n == 1) 
      return; 
  ll M[2][2] = {{1,1},{1,0}}; 
  
  power(F, n/2); 
  multiply(F, F); 
  
  if (n%2 != 0) 
     multiply(F, M); 
} 
  
void multiply(ll F[2][2], ll M[2][2]){
  ll x =  ((F[0][0]*M[0][0])%MOD + (F[0][1]*M[1][0])%MOD)%MOD; 
  ll y =  ((F[0][0]*M[0][1])%MOD + (F[0][1]*M[1][1])%MOD)%MOD; 
  ll z =  ((F[1][0]*M[0][0])%MOD + (F[1][1]*M[1][0])%MOD)%MOD; 
  ll w =  ((F[1][0]*M[0][1])%MOD + (F[1][1]*M[1][1])%MOD)%MOD; 
  
  F[0][0] = x; 
  F[0][1] = y; 
  F[1][0] = z; 
  F[1][1] = w; 
} 

int solve(){
    int n,k;
    cin>>n>>k;
    // ans is Sum(till k-1 fibonacci)*(n/k)
    // we have to calculate sum in log time and it turns out that sum(n) is fib(n+2)-1 from gfg
    long long ans=fib(k+1)-1;
    // cout<<" \nsum is "<<ans<<endl;
    ans=(((ans * (n/k))%MOD)+ (fib((n%k)+1)-1)%MOD)%MOD;
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}