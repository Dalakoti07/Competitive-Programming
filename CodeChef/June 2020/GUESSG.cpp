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

inline int maxFreq(vector<char>& tolds){// 0 means less and 1 means great
    int countL=0,countG=0;
    for(int i=0;i<3;i++) (tolds[i]=='L')? countL++ : countG++;
    if(countL<countG) return 0;
    return 1;
}

int solve(){
    int n;
    cin>>n;
    ll start=1,end=n,mid;
    vector<char> tolds(3);
    // we will ask three query in each mid and max freq in 3 questioning is answer
    while(start<=end){
        mid=(start+end)/2;
        for(int i=0;i<3;i++){
            cout<<mid<<endl;
            cin>>tolds[i];
            if(tolds[i]=='E') exit(0);
        }
        bool isLess= maxFreq(tolds);
        if(isLess){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
}

int main(){
    int t;
    t=1;
    while(t--){
        solve();
    }
}