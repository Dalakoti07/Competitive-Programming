#include<bits/stdc++.h>
using namespace std;

// using heaps
/*
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,z,count=0;
        cin>>n>>z;
        // use heap as per problem
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        make_heap(arr.begin(),arr.end());
        while(arr.size()!=0 and z>0){
            int powerfulWarrior=arr.front();
            // cout<<"devil power: "<<z<<" and warrior "<<powerfulWarrior<<" after battle "<< z-powerfulWarrior<<"\n";
            z-=powerfulWarrior;
            powerfulWarrior/=2;
            count++;
            pop_heap(arr.begin(),arr.end());
            arr.pop_back();
            if(powerfulWarrior)
                arr.push_back(powerfulWarrior);
            push_heap(arr.begin(),arr.end());
        }
        if(z==0 and arr.size()==0){
            cout<<count<<"\n";
        }else if(z<=0){
            cout<<count<<"\n";
        }else{
            cout<<"Evacuate\n";
        }
    }
}
*/

// sets
/*
For any question that can’t be done by sets because of the distinct property, the most common hack is to put in a 
pair in the set where the second element of the pair is a timestamp which differs for each element, 
thus ensuring no two elements are same (alternatively use a multiset, but while using multiset be careful on 
how you do the erase), for SAVKONO something like this:
*/
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,z,a,count=0;
        cin>>n>>z;
        set<pair<int, int> > S;
        for(int i = 1; i <= n; i++){
            cin>>a;
            S.insert({a, i});
        }
        while(z > 0 and S.size()!=0){
            // cout<<"size "<<S.size();
            pair<int, int> tmp = *S.rbegin();
            S.erase(--S.end());
            z -= tmp.first;
            count++;
            if(tmp.first/2>0)
            S.insert({tmp.first / 2, tmp.second});
        }
        if(z>0){
            cout<<"Evacuate\n";
        }else{
            cout<<count<<"\n";
        }
    }
}