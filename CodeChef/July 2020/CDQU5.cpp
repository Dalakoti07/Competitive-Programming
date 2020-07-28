#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define MOD 1000000009

using namespace std;

void init(){
  FASTIO;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

vector<ll> memoization((int)1e6 + 1,-1);

ll go(int x){
    if(memoization[x]!=-1) return memoization[x];
    if(x<=1) return 0;
    if(x==2 or x==3) return 1;
    memoization[x-2]=go(x-2);
    memoization[x-3]=go(x-3);
    return memoization[x]=  (memoization[x-2]+ memoization[x-3])%MOD;
}

void preCompute(){
    memoization[0]=memoization[1]=0;
    memoization[2]=memoization[3]=1;
    for(int i=4;i<=(int)1e6;i++){
        // this notition of or is that given a money x we can make obtained by either using a two ruppe coin and remaing coins
        // that is 1*(x-2)
        // or we can do using 3 rupee coin and remaining amount as 1*(x-3)
        // which gives us (x-2 + x-3) the recu and dp solution
        memoization[i]=(memoization[i-2]+memoization[i-3])%MOD;
    }
}

int solve(){
	int n;
    cin>>n;
    cout<<memoization[n]<<endl;
}

int main(){
    preCompute();
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}