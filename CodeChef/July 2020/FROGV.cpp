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

bool comparator(pair<int,int>& p1,pair<int,int>& p2){
    return p1.second<p2.second;
}

void solve(){
	int n,k,p,x;
    cin>>n>>k>>p;
    vector<pair<int,int>> arr;
    FOR(i,n){
        cin>>x;
        arr.pb({i+1,x});
    }
    sort(arr.begin(),arr.end(),comparator);
    // print
    // for(auto p:arr){
    //     cout<<"( "<<p.first<<" : "<<p.second<<" ) \t";
    // }

    // try one more approach that is make sets of frogs which can communicate and then take a and b check if a anf b 
    // appear in same set, u can achieve this by the help of arr with integer as set name like set one as 1, set two as
    // 2, and thus we can make n set s

    int a,b;
    while(p--){
        cin>>a>>b;
        if(a==b){
            cout<<"Yes\n";
            continue;
        }
        if(n==1){
            cout<<"Yes\n";  
            continue;
        }

        if(a>b)
            swap(a,b);
        auto itr=lower_bound(arr.begin(),arr.end(), make_pair(a,numeric_limits<int>::min()));
        int idx=itr-arr.begin();
        bool possible=true;
        // cout<<"idx :"<<idx<<endl;
        for(int i=idx+1;i<n;i++){
            if(arr[i].second-arr[i-1].second<=k)
                ;
            else{
                possible=false;
                break;
            }
            if(arr[i].first==b)
                break; // done we have meet the frog b
        }
        if(possible)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}

int main(){
    int t;
    // cin>>t;
    t=1;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}