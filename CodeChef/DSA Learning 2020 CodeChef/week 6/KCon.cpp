#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back

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

ll kadane(vector<ll>& arr,ll n){
    ll maxSumTillHere=0,maxOverAll=INT_MIN;
    for(int i=0;i<n;i++){
        maxSumTillHere+=arr[i];
        if(maxSumTillHere>maxOverAll){
            maxOverAll=maxSumTillHere;
        }
        if(maxSumTillHere<=0)
            maxSumTillHere=0;
    }
    return maxOverAll;
}

int solve(){
    ll n,k,sumOfAll=0;
    cin>>n>>k;
    vector<ll> arr(n);
    FOR(i,n){
        cin>>arr[i];
        sumOfAll+=arr[i];
    }
    // find maxPrefix and maxSuffix
    ll maxPrefix=arr[0],maxSuffix=arr[n-1];
    for(int i=1;i<n;i++)
        if(arr[i]+maxPrefix <=maxPrefix )
            break;
        else 
            maxPrefix=arr[i]+maxPrefix;
    for(int j=n-2;j>=0;j--)
        if(arr[j]+maxSuffix <=maxSuffix)
            break;
        else
            maxSuffix=arr[j]+maxSuffix;
    // cout<<" maxprefix "<<maxPrefix<<" maxsuffix "<<maxSuffix<<endl;
    ll maxSubArraySum= kadane(arr,n);
    if(k==1){
        cout<<max(maxSubArraySum,max(maxPrefix,maxSuffix))<<endl;
    }else{
        long long case1, case2, case3,case4=INT_MIN;
        case1=maxSubArraySum;
        case2=sumOfAll*k;
        case3=maxPrefix+maxSuffix;
        // cout<<" case1: "<<case1<<" case2: "<<case2<<" case3: "<<case3<<" case4: "<<case4<<endl;
        if(k>3){
            case4=maxSuffix + sumOfAll*(k-2) + maxPrefix;
            cout<<max(case1,max(case2,max(case3,case4)))<<endl;
        }
        else cout<<max(case1,max(case2,case3))<<endl;
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}