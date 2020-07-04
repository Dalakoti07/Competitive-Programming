#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k,a,b;
        cin>>n>>m>>k;
        // cannot make grid as N is 1e9 and M is also 1e9
        // but for brute force it can work, complexity is N*M

        // so we can use set which contain coordinate of all plants and then we can find for each plant if 
        // we have corresponding plants as its neighbour complexity is K, where is No. of plants
        set<pair<int,int>> plantsCoordinates;
        for(int i=0;i<k;i++){
            cin>>a>>b;
            plantsCoordinates.insert({a,b});
        }
        // calculate the answer
        int count =0;
        for(auto p: plantsCoordinates){
            pair<int,int> plant =p;
            count+=4;
            // find left neighbour
            if(plantsCoordinates.find({plant.first,plant.second-1})!=plantsCoordinates.end())
                count--;
            // find right neighbour
            if(plantsCoordinates.find({plant.first,plant.second+1})!=plantsCoordinates.end())
                count--;
            // find top neighbour
            if(plantsCoordinates.find({plant.first-1,plant.second})!=plantsCoordinates.end())
                count--;
            // find bottom neighbour
            if(plantsCoordinates.find({plant.first+1,plant.second})!=plantsCoordinates.end())
                count--;
        }
        cout<<count<<"\n";
    }
}