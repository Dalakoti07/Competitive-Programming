#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,b,m,x,count=0;
        cin>>n>>b>>m;
        cin>>x;
        int previousBatch=(x)/b,currentBatch;
        count++;
        for(int i=2;i<=m;i++){
            cin>>x;
            currentBatch=(x)/b;
            if(currentBatch!=previousBatch){
                // cout<<"adding at "<<i<<endl;
                previousBatch=currentBatch;
                count++;
            }
        }
        cout<<count<<endl;
    }
}