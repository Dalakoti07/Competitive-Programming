#include<bits/stdc++.h>
using namespace std;

int giveElementLessOrEqual(vector<int>& vec,int target){
    long long start=0,end=vec.size(),mid;
    long long idx;
    // cout<<" \n------------------- search start -------------------";
    while(start<=end){
        mid = (start+end)/2;
        // cout<<" mid : "<<mid;
        if(vec[mid]<=target){
            if(vec[mid]==target) return target;
            start=mid+1;
            idx=mid;
        }else if(vec[mid]>target){
            end=mid-1;
        }
    }
    // cout<<"returning idx"<<idx<<" and value "<<vec[idx];
    // cout<<" \n------------------- search end -------------------";
    return vec[idx];    
}

int giveElementGreaterOrEqual(vector<int>& vec,int target){
    long long start=0,end=vec.size(),mid;
    long long idx;
    // cout<<" \n------------------- search start -------------------";
    while(start<=end){
        mid = (start+end)/2;
        // cout<<" mid : "<<mid;
        if(vec[mid]>=target){
            if(vec[mid]==target) return target;
            end=mid-1;
            idx=mid;
        }else if(vec[mid]<target){
            start=mid+1;
        }
    }
    // cout<<"returning idx"<<idx<<" and value "<<vec[idx];
    // cout<<" \n------------------- search end -------------------";
    return vec[idx];    
}

int main(){
    int n,x,y,a,b;
    cin>>n>>x>>y;
    vector<pair<int,int>> events;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        events.push_back({a,b});    
    }
    vector<int> arrivalTime(x);
    vector<int> departureTime(y);
    for(int i=0;i<x;i++){
        cin>>arrivalTime[i];
    }
    for(int i=0;i<y;i++){
        cin>>departureTime[i];
    }
    // ans calculation
    sort(arrivalTime.begin(),arrivalTime.end());
    sort(departureTime.begin(),departureTime.end());

    int maxAns=INT_MAX;
    // lowebound gives index of eleme >= to it
    // uppperbound gives index of eleme > to it
    for(int i=0;i<n;i++){
        if(events[i].second >departureTime[departureTime.size()-1]){
            continue;
        }
        if(events[i].first <arrivalTime[0]){
            continue;
        }
        int idx1Elem= giveElementLessOrEqual(arrivalTime,events[i].first);
        
        int idx2Elem= giveElementGreaterOrEqual(departureTime,events[i].second);
        
        // cout<<" elem1 "<<idx1Elem<<" and eleme2 "<<idx2Elem<<"\n";
        maxAns=min(maxAns,idx2Elem-idx1Elem+1);
    }
    cout<<maxAns<<"\n";
}