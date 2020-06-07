#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,ans=0,index=1;
        cin>>x;
        int div=x/pow(5,index);
        while(div!=0){
            ans+=div;
            index++;
            div=x/pow(5,index);
        }
        cout<<ans<<endl;
    }
}