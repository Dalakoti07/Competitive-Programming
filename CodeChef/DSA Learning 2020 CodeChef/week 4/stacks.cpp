#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;

        // multistack took 0.5 secs and whereas vector took 1.2 seconds 
        // long live multistack
        multiset<int> stacksCollection;
        for(int i=0;i<n;i++){
            cin>>x;
            auto lBound=stacksCollection.upper_bound(x);
            if(lBound==stacksCollection.end()){
                stacksCollection.insert(x);
                // cout<<" inserting "<<x<<"\n";
            }
            else{
                // cout<<" erasing "<<*lBound<<" and inserting "<<x<<"\n";
                stacksCollection.erase(lBound);
                stacksCollection.insert(x);
            }
        }
        cout<<stacksCollection.size()<<" ";
        for(int i: stacksCollection){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}