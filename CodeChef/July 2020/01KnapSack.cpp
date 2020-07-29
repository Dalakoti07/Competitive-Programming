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

int go(vector<int>& arrVal,vector<int>& wtArr,int idx,int n,int weightSoFar,int maxWeight,int costSoFar){
    if(idx==n){
        if(weightSoFar>maxWeight) return INT_MIN;
        else return costSoFar;
    }
    if(weightSoFar>maxWeight) return INT_MIN;
    // cout<<"at idx: "<<idx<<" weightSoFar"<<weightSoFar<<" and maxWt: "<<maxWeight<<" and costSoFar :"<<costSoFar<<endl;
    int one = go(arrVal,wtArr,idx+1,n,weightSoFar+wtArr[idx],maxWeight,costSoFar+arrVal[idx]);
    int two = go(arrVal,wtArr,idx+1,n,weightSoFar,maxWeight,costSoFar);
    return max(one,two);
}

void solve(){
	int n, weights;
    cin>>n>>weights;
    vector<int> arrVal(n),wtArr(n);
    FOR(i,n)
        cin>>arrVal[i];
    FOR(i,n)
        cin>>wtArr[i];
    cout<<go(arrVal,wtArr,0,n,0,weights,0)<<endl;
}

int main(){
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}