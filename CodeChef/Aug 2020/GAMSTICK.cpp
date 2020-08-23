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
	ll n,x1,y1,x2,y2;
    cin>>n>>x1>>y1>>x2>>y2;
    bool swapable=false;
    if(y1==y2){
        cout<<"Draw\n";
        return;
    }
    if(y1>y2){
        swapable=true;
        swap(y1,y2);
    }
    ll scoreM=0,scoreS=0;
    scoreM+=(y1-1)*2 + 1;
    scoreS+=(n-y2)*2 + 1;
    if(y1+1 == y2){
        scoreM+=0;
    }else{
        scoreM+=(y2-y1);
        scoreS+=(y2-y1);
    }
    if(swapable)
        swap(scoreS,scoreM);
    if(scoreM>scoreS){
        cout<<"Miron\n";
    }else if(scoreS>scoreM){
        cout<<"Slava\n";
    }else{
        cout<<"Draw\n";
    }
}

int main(){
    int t=1;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}