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

// print vector
// print vector of pair int
// print hashmap

int solve(){
	int n;
    cin>>n;
    string str;
    cin>>str;
    int count=0;
    vector<bool> itsSelfOrForwardCanDestroyIt(n,false);
    for(int i=0;i<n-1;i++){
        if(str[i]=='1')
            count++,itsSelfOrForwardCanDestroyIt[i]=true;
        else if(str[i+1]=='1'){
            itsSelfOrForwardCanDestroyIt[i]=true;
            count++;
        }
    }
    if(str[n-1]=='1'){
        count++;
        itsSelfOrForwardCanDestroyIt[n-1]=true;
    }
    for(int i=n-1;i>=0;i--){
        if(!itsSelfOrForwardCanDestroyIt[i]){
            if(str[i-1]=='1')
                count++;
        }
    }
    cout<<n-count<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}