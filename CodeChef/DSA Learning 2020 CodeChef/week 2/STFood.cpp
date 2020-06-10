#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        int ans=-1;
        cin>>n;
        int s,p,v;
        while(n--){
            cin>>s>>p>>v;
            ans=max(ans,(p/(s+1))*v);
        }
        cout<<ans<<endl;
    }
}