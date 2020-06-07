#include<bits/stdc++.h>
using namespace std;

// beautiful question
int main(){
    unsigned long long t,x,i=0,mini=INT_MAX,maxi=INT_MIN;
    vector<int> prices;
    cin>>t;
    while(i<t){
        cin>>x;
        i++;
        prices.push_back(x);
    }
    sort(prices.begin(), prices.end());
    unsigned long long ans=1; 
    // finding suitable revenue
    for(int i=0;i<t;i++){
        ans=max(ans,prices[i]*(t-i));
    }
    cout<<ans;
}