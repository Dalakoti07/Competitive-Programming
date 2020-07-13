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

/*
    What does this problem taught
    codes become 2 time slower when using long long instead of int
    Don't underestimate greedy
    map[key] return 0 if key is absent dont check if count ==0 and then 
    No need to make array ll unnecessarily as it can increase time execution and promote TLE
*/

// https://discuss.codechef.com/t/chfnswps-editorial/71067

void init(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

// print vector
// print vector of pair int
// print hashmap

void solve(){
    int n,x;
    cin>>n;
    vector<int> vec1(n),vec2(n);
    map<int,int> mappy;
    for(int i=0;i<n;i++){
        cin>>x;
        mappy[x]++;
        vec1[i]=x;
    }
    for(int i=0;i<n;i++){
        cin>>x;
        mappy[x]--;
        vec2[i]=x;
    }
    // now if mapp[i] is >0 means vec1 had that element in acces or vice versa
    vec1.clear();
    vec2.clear();
    int minimum=INT_MAX;
    bool isPossible=true;
    for(auto m: mappy){
        minimum=min(m.first,minimum);
        if(abs(m.second)%2){
            isPossible=false;
            break;
        }
        if(m.second>0){
            int s=(m.second)/2;
            while(s--)
                vec1.push_back(m.first);
        }else{
            int s=(abs(m.second))/2;
            while(s--)
                vec2.push_back(m.first);
        }
    }
    if(!isPossible){
        cout<<"-1\n";
        return;
    }
    // calculation time
    // and its sure that vec2 and vec1 are equal in size
    ll cost=0;
    // no need to do sorting as elements were sorted as per key in map stl !
    // sort(vec1.begin(),vec2.end());
    // sort(vec2.begin(),vec2.end());
    // as discussed we had two types of swaps, one with the help of min elem and other min(arr1[i],arr1[i])
    // now we dont want to fight with min(min of vec1, min of vec2 ), thus we would be greedy and would reverse one array
    reverse(vec2.begin(),vec2.end());
    for(int i=0;i<vec1.size();i++)
        cost+=min((ll)2*minimum,min((ll)vec1[i],(ll)vec2[i]));
    cout<<cost<<endl;
    // this was hell 
}

int main(){
    FASTIO;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}