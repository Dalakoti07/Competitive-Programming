#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q,x;
        cin>>n>>q;
        long long arr1[n],arr2[n];
        for(int i=0;i<n;i++)
            cin>>arr1[i];
        for(int i=0;i<n;i++)
            cin>>arr2[i];
        
        sort(arr1,arr1+n);
        sort(arr2,arr2+n);

        vector<long long> sum;
        for(int i=0;i<n and i<500;i++){
            for(int j=0;j<n and j<500;j++){
                sum.push_back(arr1[i]+arr2[j]);
            }
        }

        sort(sum.begin(),sum.end());

        while(q--){
            cin>>x;
            cout<<sum[x-1]<<"\n";
        }
    }
}