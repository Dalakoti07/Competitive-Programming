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

bool go(int arr[],int moneyAsked,int notes){
    // cout<<"\nnotes with us \n";
    // for(int i=0;i<notes;i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl<<" and money req is "<<moneyAsked<<"\n";

    if(moneyAsked<0)
        return false;
    if(moneyAsked==0){
        return true;
    }else if(moneyAsked>0 and notes==0){
        return false;
    }else{
        bool one= go(arr+1,moneyAsked-arr[0],notes-1);// include first note
        bool two =go(arr+1,moneyAsked,notes-1);// exclude first note
        if(one or two)
            return true;
        return false; 
    }
}

int solve(){
    int n,moneyAsked;
    cin>>n>>moneyAsked;
    int arr[n];
    FOR(i,n)
        cin>>arr[i];
    bool ans =go(arr,moneyAsked,n);
    if(ans)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}