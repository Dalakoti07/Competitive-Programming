#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define MOD 1e9+7
#define deb(x) cout<< #x << " = "<<x<<endl;

using namespace std;

void init(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

// code from below


void solve(){
	ll n;
    cin>>n;
    ll sum=((n+1)*n)/2;
    if(sum%2)
        cout<<0<<endl;
    else{
        // calculate the min swaps
        // answer would be length of subarray + 1, from last such that sum is n/2 or less than n/2
        // the quadratic equation for length would be l^2 + (2*n + 1)l + SumOfAllElem
        // not working
        
        // brute force approach is go from n to .... backward such that total sum is <=n/2

        // missing some test cases
        int sumSoFar=0,count=0;
        for(int i=n;i>=1;i--){
            sumSoFar+=i;
            count++;
            if (sumSoFar>sum/2)
                break;
        }
        cout<<count<<endl;
    }
}

int main(){
    int t=1;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}