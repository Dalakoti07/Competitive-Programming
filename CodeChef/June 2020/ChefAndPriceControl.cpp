#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,x;
        long long int ans=0;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>x;
            if(x>k){
                ans+=x-k;
            }
        }
        cout<<ans<<"\n";
    }
}