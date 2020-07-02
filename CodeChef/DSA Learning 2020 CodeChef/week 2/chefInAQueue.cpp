#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    stack<pair<int,int>> elemeAndIdx;
    ll prod=1;
    for(int i=n-1;i>=0;i--){
        while(!elemeAndIdx.empty() and elemeAndIdx.top().first>=arr[i]){
            elemeAndIdx.pop();
        }
        if(!elemeAndIdx.empty()){
            prod= prod%mod * (elemeAndIdx.top().second - i +1)%mod;
        }
        elemeAndIdx.push({arr[i],i});
    }
    /* TLE
    ll prod=1;
    for(ll i=n-2;i>=0;i--){
        for(ll j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                prod=(prod%mod) *  (j-i+1)%mod;
                break;
            }
        }
    }
    */
    cout<<prod<<endl;
}