#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back

using namespace std;

void init(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

vector<bool> allPrimes(10001,true);

void PreCompute(){
    for(int i=1;i<=10000/2;i++){
        if(allPrimes[i]==true)
        for(int j=i;j<=10000;j=j+i){
            allPrimes[j]=false;
        }
    }
    // all primes are marked as true
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