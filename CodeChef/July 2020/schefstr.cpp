#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,last,current;
        cin>>n;
        long long count=0;
        cin>>last;
        for(int i=1;i<n;i++){
            cin>>current;
            count+=abs(current-last)-1;
            // cout<<"diff of "<<last<<" and "<<current<<" diff is "<<abs(current-last-1)<<" ans is :"<<count<<"\n";
            last=current;
        }
        cout<<count<<"\n";
    }
}