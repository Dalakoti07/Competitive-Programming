#include<bits/stdc++.h>
using namespace std;

/*
    What does this problem taught
    codes become 2 time slower when using long long instead of int
    Don't underestimate greedy
    map[key] return 0 if key is absent dont check if count ==0 and then 
*/

long long go(map<int,int>& commonElements,map<int,int>& elementsInA,map<int,int>& elementsInB,int minINBoth){
    for(auto m:commonElements){
        if(m.second%2)
            return -1;
    }
    long long ans=0;
    // see elemens in A
    vector<int> extraElementsWithA,extraElementsWithB;
    for(auto m:elementsInA){
        int x=elementsInB[m.first];
        if(x<m.second){
            for(int i=0;i<(m.second-x)/2;i++)
                extraElementsWithA.push_back(m.first);
        }else{
            for(int i=0;i<(x-m.second)/2;i++)
                extraElementsWithB.push_back(m.first);
        }
    }

    for(auto m:elementsInB){
        if(elementsInA.count(m.first)==0){
            for(int i=0;i<m.second/2;i++)
                extraElementsWithB.push_back(m.first);
        }
    }

    sort(extraElementsWithA.begin(),extraElementsWithA.end());
    sort(extraElementsWithB.begin(),extraElementsWithB.end());
    ans=0;
    long long l=0;
    long long n=extraElementsWithA.size();
    vector<int> results;
    for(int i=0;i<n;i++){
        if(extraElementsWithA[i]<2*minINBoth)
            results.push_back(extraElementsWithA[i]);
        if(extraElementsWithB[i]<2*minINBoth)
            results.push_back(extraElementsWithB[i]);
    }
    sort(results.begin(),results.end());
    int x=results.size();
    if(x>=n){
        for(int i=0;i<n;i++)
        ans+=(long long)results[i];
        return ans;
    }
    for(int i=0;i<x;i++){
        ans+=(long long)results[i];
    }
    l=2*n-2*x;
    ans+=l*minINBoth;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,x,minINBoth=INT_MAX;
        cin>>n;
        map<int,int> commonElements, elementsInA, elementsInB;
        for(int i=0;i<n;i++){
            cin>>x;
            commonElements[x]+=1;
            elementsInA[x]+=1;
            minINBoth=min(minINBoth,x);
        }
        for(int i=0;i<n;i++){
            cin>>x;
            commonElements[x]+=1;
            elementsInB[x]+=1;
            minINBoth=min(minINBoth,x);
        }

        cout<<go(commonElements,elementsInA,elementsInB,minINBoth)<<"\n";
    }
}