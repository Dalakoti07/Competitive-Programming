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

// print vector
// print vector of pair int
// print hashmap

int solve(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    int reqPower=m-1,reqKnow=n-1;
    if(reqPower%y==0 and reqKnow%x==0){// not using sharechat
        cout<<"Chefirnemo";
    }else if(reqPower>0 and reqKnow>0 and (reqPower-1)%y==0 and (reqKnow-1)%x==0){//using sharechat
        cout<<"Chefirnemo";
    }else{// if above doesnot hold than ans is no
        cout<<"Pofik";
    }
    cout<<endl;
}

int main(){
    // FASTIO;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}