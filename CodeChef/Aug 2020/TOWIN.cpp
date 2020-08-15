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
	// it can be simulated
    int n;
    cin>>n;
    vi arr(n);
    ll overAllSum=0;
    FOR(i,n){
        cin>>arr[i];
        overAllSum+=arr[i];
    }
    ll sumFirst=arr[0],sumSecond=0;
    sort(arr.begin(),arr.end(),greater<int>());

    if(n==1 or n==2){
        if(n==1)
            cout<<"first\n";
        else if(n==2){
            if(arr[0]==arr[1])
                cout<<"draw\n";
            else
                cout<<"first\n";
        }
        return;
    }

    // max sum when played first
    for(int i=3;i<n;i+=2){
        sumFirst+=arr[i];
    }
    ll otherFirst=overAllSum-sumFirst;
    if(sumFirst>otherFirst){
        cout<<"first\n";
        return;
    }

    // second played
    sumSecond=arr[1]+arr[2];
    for(int i=4;i<n;i+=2)
        sumSecond+=arr[i];

    ll otherSecond=overAllSum-sumSecond;
    if(otherSecond<sumSecond){
        cout<<"second\n";
        return;
    }

    cout<<"draw\n";
}

int main(){
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}