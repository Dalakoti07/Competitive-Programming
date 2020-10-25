#include <bits/stdc++.h>
using namespace std ;


int main(){
    int intWall,outWall;
    float x;
    vector<float> SAIntWall;
    vector<float> SAOutWall;
    cin>>intWall>>outWall;
    for(int i=0;i<intWall;i++){
        cin>>x;
        SAIntWall.push_back(x);
    }
    for(int i=0;i<outWall;i++){
        cin>>x;
        SAOutWall.push_back(x);
    }

    // answer
    float ans=0.0;
    for(float a:SAIntWall){
        ans+=a*18;
    }
    for(float a:SAOutWall){
        ans+=a*12;
    }
    cout<<"Total estimated cost:"<<ans<<" INR";
}