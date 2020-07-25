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

int solve(){
	int n;
    cin>>n;
    vi arr(n),freq(2100,0);
    FOR(i,n){
        cin>>arr[i];
        freq[arr[i]+1000]++;
    }
    // exploiting the constraints that a[i]<=1000 and we have 10^5 elems
    ll count=0;
    for(int i=0;i<=2000;i++){
        for(int j=0;j<=2000;j++){
            if((i+j)%2==0 and freq[i] and freq[j] and freq[(i+j)/2]){
                if(i!=j){
                    count+=(1LL)*freq[i]*freq[j];
                }
                else 
                    count+=((1LL)*freq[i]*(freq[i]-1));
            }
        }
    }
    cout<<count/2<<endl;
}

int main(){
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}