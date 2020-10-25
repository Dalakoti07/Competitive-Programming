#include <bits/stdc++.h>
using namespace std ;

int main(){
    vector<pair<string,int>> routes;
    routes.push_back({"TH",800});
    routes.push_back({"GA",600});
    routes.push_back({"IC",750});
    routes.push_back({"HA",900});
    routes.push_back({"TE",1400});
    routes.push_back({"LU",1200});
    routes.push_back({"NI",1100});
    routes.push_back({"CA",1500});

    string start,des;
    int startIdx=-1,desIdx=-1,idx=0;
    cin>>start>>des;
    //check route
    bool found=false;
    for(auto e: routes){
        if(e.first==start){
            found=true;
            startIdx=idx;
            break;
        }
        idx++;
    }
    if(!found){
        cout<<"INVALID INPUT";
        return 0;
    }
    idx=0;
    found=false;
    for(auto e: routes){
        if(e.first==des){
            found=true;
            desIdx=idx;
            break;
        }
        idx++;
    }
    if(!found){
        cout<<"INVALID INPUT";
        return 0;
    }

    // valid path
    float ans=0;
    for(int x=startIdx;x!=desIdx;x=(x+1)%8){
        cout<<" adding "<<routes[(x+1)%8].second<<"\n";
        ans+=routes[(x+1)%8].second;
    }
    cout<<(float)ceil(ans*(0.005f))<<" INR";
}