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
	int n,k,x;
    cin>>n>>k;
    pair<int,int> answers={INT_MAX,INT_MAX};
    FOR(i,n){
        cin>>x;
        if(k%x ==0){
            int laps=k/x;
            if(answers.second> laps){
                answers.second=laps;
                answers.first=x;
            }
        }
    }
    if(answers.first==INT_MAX)
        cout<<-1<<endl;
    else
        cout<<answers.first<<endl;
}

int main(){
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}