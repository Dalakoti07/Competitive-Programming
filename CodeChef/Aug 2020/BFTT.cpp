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

inline bool containsAtleast3(string n){
    // cout<<"string is : "<<n;
    int count=0;
    for(auto c: n){
        if(c=='3') count++;
    }
    return count>=3;
}

void solve(){
	int n;
    cin>>n;
    int ans=n;
    string str_ans;
    ll i=n+1;
    while(1){
        str_ans=to_string(i);
        if(containsAtleast3(str_ans)){
            ans=i;
            break;
        }
        i++;
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}