#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<int,int>& a ,pair<int,int>& b){
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n;
        vector<pair<int,int>> vertices(4*n-1);
        for(int i=0;i<4*n-1;i++){
            cin>>a>>b;
            vertices[i]={a,b};
        }
        sort(vertices.begin(),vertices.end(),comparator);
        /*cout<<"\n\n";
        for(auto p: vertices){
            cout<<p.first<<" "<<p.second<<"\n";
        }*/
        // for each x corrdinate we must have even number of y coordinates with this x value
        unordered_map<int,int> helpMap;// this store ocuurence of y coordinate
        int currentXValue,yCoordinateCount=0;
        for(int i=0;i<vertices.size();){
            currentXValue=vertices[i].first;
            if(helpMap.count(vertices[i].second)==0){
                helpMap[vertices[i].second]=1;
            }else{
                helpMap[vertices[i].second]+=1;
            }
            i++;
            yCoordinateCount+=1;
            while(vertices[i].first==currentXValue){
                if(helpMap.count(vertices[i].second)==0){
                    helpMap[vertices[i].second]=1;
                }else{
                    helpMap[vertices[i].second]+=1;
                }
                i++;
                yCoordinateCount+=1;
            }
            if(yCoordinateCount%2){
                int reqX=vertices[i-1].first,reqY=-1;
                // find the y coordinate from map
                for(auto i:helpMap){
                    cout<<"y coor: "<<i.first<<" count "<<i.second<<"\n";
                    if(i.second%2==1)
                        reqY=i.first;
                }
                cout<<reqX<<" "<<reqY<<"\n";
                // break out of loop
                break;
            }
        }
    }
}