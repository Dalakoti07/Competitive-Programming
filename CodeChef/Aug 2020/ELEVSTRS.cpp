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
	int n,v1,v2;
    double t1,t2;
    cin>>n>>v1>>v2;
    t1=(sqrt(2)*(double)n)/(double)v1;
    t2=(double(2)*(double)n)/(double)v2;
    if(t1<t2){
        cout<<"Stairs\n";
    }else
        cout<<"Elevator\n";
}

int main(){
    int t=1;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}