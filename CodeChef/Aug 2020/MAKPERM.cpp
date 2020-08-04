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

// int freq[int(1e9)+1];
void solve(){
    // memset(freq,0,sizeof(freq));
	int n,x;
    map<int,int> mappy;
    cin>>n;
    FOR(i,n){
        cin>>x;
        mappy[x]++;
    }
    int count=0;
    auto itr= mappy.begin();
    int lastElem=itr->first,currElem;
    // if(itr->second>1 )
    //     count+=itr->second-1;
    // itr++;
    for(;itr!=mappy.end();itr++){
        currElem=itr->first;
        if(itr->second>1 and currElem<=n)
            count+=itr->second-1;
        else if(currElem>n)
            count+=itr->second;
            
    }
    cout<<count<<endl;
}

int main(){
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}