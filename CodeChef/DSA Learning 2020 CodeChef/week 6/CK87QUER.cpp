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
  FASTIO;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

// print vector
// print vector of pair int
// print hashmap

vector<int> allSquares;

void precompute(){
    int no=1;
    while(no<=(int) 1e5){
        allSquares.pb(no*no);
        no++;
    }
}

int solve(){
    long long n,count=0;
    cin>>n;
    for(int b=1;b<=700;b++){
        if(n-b <=0)
            break;
        count+=sqrt(n-b);
    }
    cout<<count<<endl;
}

int main(){
    int t;
    cin>>t;
    // precompute();
    while(t--){
        solve();
    }
}