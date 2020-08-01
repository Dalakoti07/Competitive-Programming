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


void solve(){
	ll n,k,x;
    cin>>n>>k>>x;
    vi arr(k);
    FOR(i,k)
        cin>>arr[i];
    ll allCandies=0;

    // add a dummy point which is maxPossible+1 at the array end that would reduce code from 39 line to 47 line
    sort(arr.begin(),arr.end());
    ll itemReq=n-k;
    if(itemReq>0){
        // get elems after arr ends
        ll maxElemPossible=x+arr[0];
        auto itr=lower_bound(arr.begin(),arr.end(),maxElemPossible);
        if(itr==arr.end()){
            // cout<<"could not find max "<<endl;
            ll elemsWeCanGet=maxElemPossible-(arr[k-1]+1)+1;
            // cout<<" elem we can get "<<elemsWeCanGet<<endl;
            ll elemsShouldBeTaken=min(elemsWeCanGet,itemReq);
            // cout<<" elem should be taken "<<elemsShouldBeTaken<<" maxElem possible "<<maxElemPossible<<endl;
            allCandies+=((elemsShouldBeTaken)*( 2*maxElemPossible + (elemsShouldBeTaken-1)*-1 ))/2;
            itemReq-=elemsShouldBeTaken;
        }
        // cout<<" after end array elems taken candies: "<<allCandies<<endl;
        // get elems between the arr
        allCandies+=arr[k-1];
        // cout<<"at 45 allCandies "<<allCandies<<endl;
        for(ll i=k-2;i>=0 ;i--){
            if(itemReq>0){
                // cout<<"at 48 allCandies "<<allCandies<<endl;
                ll elemeMissing=arr[i+1]-arr[i]-1;
                elemeMissing=min(itemReq,elemeMissing);
                // cout<<" adding + "<<((elemeMissing)*(2*(arr[i+1]-1) - (elemeMissing-1) ))/2<<" cadies\n";
                allCandies+=((elemeMissing)*(2*(arr[i+1]-1) - (elemeMissing-1) ))/2;
                allCandies+=arr[i];
                // cout<<" after adding missing elem and after idx i: "<<i<<"  cand: "<<allCandies<<endl;
                itemReq-=elemeMissing;
            }else
                allCandies+=arr[i];
        }
    }else{
        allCandies+=arr[k-1];
        for(ll i=k-2;i>=0;i--){
            allCandies+=arr[i];        
        }
    }
    cout<<allCandies<<endl;
}

int main(){
    int t;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
        solve();
    }
}