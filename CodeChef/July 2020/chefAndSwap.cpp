#include<bits/stdc++.h>
using namespace std;
//A--->0 0 0 0 4 4
// B--->1 1 2 2 3 3 ans 3

long long go(unordered_map<int,long long>& commonElements,unordered_map<int,long long>& elementsInA,unordered_map<int,long long>& elementsInB){
    for(auto m:commonElements){
        if(m.second%2)
            return -1;
    }
    set<int> elemetsSeen;
    long long count=0;
    // see elemens in A
    for(auto m:elementsInA){
        elemetsSeen.insert(m.first);
        if(elementsInB.count(m.first)==0){
            cout<<" transferring "<<m.first<<" takes "<<m.second/2<<"\n";
            count+=m.second/2;
        }else{
            cout<<" transferring "<<m.first<<" takes "<<abs(m.second-elementsInB[m.first])/2<<"\n";
            count+=abs(m.second-elementsInB[m.first])/2;
        }
    }
    // see elements in B
    for(auto m:elementsInB){
        if(elemetsSeen.find(m.first)==elemetsSeen.end()){
            cout<<" transferring "<<m.first<<" takes "<<m.second/2<<"\n";
            count+=m.second/2;
        }
    }
    return count/2;
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        unordered_map<int,long long> commonElements, elementsInA, elementsInB;
        for(int i=0;i<n;i++){
            cin>>x;
            if(commonElements.count(x)==0)
                commonElements[x]=1;
            else 
                commonElements[x]+=1;
            if(elementsInA.count(x)==0)
                elementsInA[x]=1;
            else
                elementsInA[x]+=1;
        }
        for(int i=0;i<n;i++){
            cin>>x;
            if(commonElements.count(x)==0)
                commonElements[x]=1;
            else 
                commonElements[x]+=1;
            if(elementsInB.count(x)==0)
                elementsInB[x]=1;
            else
                elementsInB[x]+=1;
        }

        cout<<go(commonElements,elementsInA,elementsInB)<<"\n";
    }
}