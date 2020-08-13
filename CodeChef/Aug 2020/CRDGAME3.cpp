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
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

// code from below

void solve(){
	int a,b;
    cin>>a>>b;
    int intASize=0,intBSize=0;
    while(a>9){
        intASize=a/9;
        a=a%9;
    }
    if(a>0)
        intASize++;
    
    while(b>9){
        intBSize=b/9;
        b=b%9;
    }
    if(b>0)
        intBSize++;
    
    // cout<<"<--- debug intASize size: "<<intASize<<" and intBSize size: "<<intBSize<<endl;

    if(intASize<intBSize)
        cout<<0<<" "<<intASize<<endl;
    else
        cout<<1<<" "<<intBSize<<endl;
}

int main(){
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}