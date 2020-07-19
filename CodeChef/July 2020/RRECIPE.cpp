#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define MOD 10000009

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

int solve(){
	string dish;
    cin>>dish;
    ll count =1;
    int n= dish.length(),i=0,j=n-1;
    if(n==1){
        if(dish[0]=='?')
            count*=26;
        else
            count=1;
    }else{
        for(;i<=j;i++,j--){
            if(dish[i]==dish[j] and dish[i]=='?')
                count=(count*26)%MOD;
            else if(dish[i]=='?' or dish[j]=='?')
                count*=1;
            else if(dish[i]!=dish[j]){
                count=0;
                break;
            }
        }
    }
    cout<<count<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}