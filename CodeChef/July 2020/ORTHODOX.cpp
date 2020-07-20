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

// please always use ll, its heart breaking

// print vector
// print vector of pair int
// print hashmap

bool bruteForce(vector<ll>& arr){
    set<ll> uniqueElem;
    set<ll>:: iterator itr;
    for(ll i=0;i<arr.size();i++){
        ll temp=arr[i];
        itr=uniqueElem.find(temp);
        if(itr!=uniqueElem.end())
            return false;
        uniqueElem.insert(temp);
        for(ll j=i+1;j<arr.size();j++){
            temp= (temp | arr[j]);
            if(uniqueElem.find(temp)!=uniqueElem.end())
                return false;
            uniqueElem.insert(temp);
        }
    }
    return true;
}

int solve(){
	
    int n;
    
    cin>>n;
    vector<long long> arr(n);
    FOR(i,n){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    if(bruteForce(arr))
        cout<<"YES\n";
    else
        cout<<"NO\n";
}

int main(){
    FASTIO;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}