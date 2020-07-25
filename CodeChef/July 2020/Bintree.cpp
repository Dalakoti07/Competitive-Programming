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

// LCA can be used for min path
// LCA is standard way of finding path and count of nodes of certain properties
int solve(){
    long long int i,j,n=0;
    cin>>i>>j;

    while(i!=j){
        if(i>j)
        {
            i=i/2;
            n++;

        }
        if(j>i)
        {
            j=j/2;
            n++;
        }
    }
    cout<<n<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}