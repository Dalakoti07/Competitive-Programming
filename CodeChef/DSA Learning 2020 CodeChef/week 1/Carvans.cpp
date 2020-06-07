#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,maxSpeedAllowed,count=1;
        cin>>n;
        cin>>maxSpeedAllowed;
        for(int i=1;i<n;i++){
            cin>>x;
            if(x<=maxSpeedAllowed){
                count++;
                maxSpeedAllowed=x;
            }else{
                maxSpeedAllowed=min(maxSpeedAllowed,x);
            }
        }
        cout<<count<<endl;
    }
}