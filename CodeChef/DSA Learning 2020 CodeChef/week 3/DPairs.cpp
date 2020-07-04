#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,x;
    cin>>n>>m;
    vector<pair<int,int>> arr1(n),arr2(m);
    for(int i=0;i<n;i++){
        cin>>x;
        arr1[i]={x,i};
    }
    for(int i=0;i<m;i++){
        cin>>x;
        arr2[i]={x,i};
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    vector<pair<int,int>> xAndYs;
    
    // get N pairs
    for(int i=0;i<n;i++)
        xAndYs.push_back({arr1[i].second,arr2[0].second});
    // get the M-1 pairs
    int idx=n-1;
    for(int i=1;i<m;i++){
        xAndYs.push_back({arr1[idx].second,arr2[i].second});
    }
    for(auto p: xAndYs){
        cout<<p.first<<" "<<p.second<<"\n";
    }
}