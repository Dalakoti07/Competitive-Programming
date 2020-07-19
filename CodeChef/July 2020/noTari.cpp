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

int solve(int n){
	vector<ll> arr(n);
    FOR(i,n)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    ll PossibleTriangleCount =0;
    ll possibleCombination=(n*(n-1)*(n-2))/6;
    // using two pointer technique
    for(int i=n-1;i>=1;i--){
        int l =0,r=i-1;
        while(l<r){
            if(arr[l]+arr[r] >= arr[i]){
                PossibleTriangleCount+=r-l;
                r--;
            }else{
                l++;
            }
        }
    }
    cout<< possibleCombination-PossibleTriangleCount<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t){
        solve(t);
        cin>>t;
    }
}