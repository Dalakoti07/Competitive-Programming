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

bool bruteForce(vector<int>& arr){
    set<int> uniqueElem;
    set<int>:: iterator itr;
    for(int i=0;i<arr.size();i++){
        int temp=arr[i];
        // cout<<"\n\nat i: "<<i<<" OR is "<<temp<<endl;
        itr=uniqueElem.find(temp);
        if(itr!=uniqueElem.end())
            return false;
        uniqueElem.insert(temp);
        for(int j=i+1;j<arr.size();j++){
            temp= (temp | arr[j]);
            // cout<<" from i: "<<i<<" to j: "<<j<<" we have "<<temp<<endl;
            if(uniqueElem.find(temp)!=uniqueElem.end())
                return false;
            // cout<<"OR of "<<arr[i]<<" and "<<arr[j]<<" is "<<(arr[i]|arr[j])<<endl;
            uniqueElem.insert(temp);
        }
    }
    return true;
}

int solve(){
	
    int n;
    
    cin>>n;
    vi arr(n);
    FOR(i,n){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    if(bruteForce(arr))
        cout<<"YES\n";
    else
        cout<<"NO\n";
    /*
    int ORTillNow=arr[0];
    bool ans=true;
    for(int i=1;i<n;i++){
        ORTillNow=ORTillNow|arr[i];
        if(ORTillNow==arr[i])
            {ans=false;break;}
    }
    if(ans)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    */
}

int main(){
    // FASTIO;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}