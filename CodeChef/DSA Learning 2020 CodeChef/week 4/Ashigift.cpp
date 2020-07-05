#include<bits/stdc++.h>
using namespace std;

bool checkIfSufficientSoldiers(int start[],int minReq[],int pop[],vector<pair<int,int>>& dishes,long long soldierWithUs,int clansOnWay){
    int noOfDishes=dishes.size();
    int currentDishIdx=0,currentClanIdx=0;
    while(currentClanIdx<clansOnWay and currentDishIdx<noOfDishes){
        if(start[currentClanIdx]<dishes[currentDishIdx].first)// we have clan to deal with
        {
            if(minReq[currentClanIdx]<=soldierWithUs){// claned joined them
                soldierWithUs+=pop[currentClanIdx];
            }
            currentClanIdx++;
        }
        else{// we are to eat dish
            if(dishes[currentDishIdx].second >=soldierWithUs){
                return false;
            }
            soldierWithUs-=dishes[currentDishIdx].second;
            currentDishIdx++;
        }
    }
    if(currentDishIdx==noOfDishes){
        if (soldierWithUs==0) 
            return false;
        else 
            return true;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int distance,noOfDishes,clansOnWay;
        long long a,b;
        cin>>distance;
        long long count=0;
        cin>>noOfDishes;
        vector<pair<int,int>> dishes(noOfDishes);
        for(int i=0;i<noOfDishes;i++){
            cin>>a>>b;
            dishes[i]={a,b};
            count+=b;
        }
        cin>>clansOnWay;
        if(clansOnWay==0){
            cout<<count+1<<"\n";
        }else{
            int p[clansOnWay],q[clansOnWay],r[clansOnWay];
            for(int i=0;i<clansOnWay;i++){
                cin>>p[i]>>q[i]>>r[i];
            }
            // binary search on number of soldiers we can use
            long long minSoldiers=1,maxSoldiers=count,optimalCount,mid;
            while(minSoldiers<=maxSoldiers){
                mid=minSoldiers - (minSoldiers-maxSoldiers)/2;
                // cout<<" soldier : "<<mid;
                if(checkIfSufficientSoldiers(p,q,r,dishes,mid,clansOnWay)){
                    optimalCount=mid;
                    maxSoldiers=mid-1;
                }else{
                    minSoldiers=mid+1;
                }
            }
            cout<<optimalCount<<"\n";
        }
    }
}

