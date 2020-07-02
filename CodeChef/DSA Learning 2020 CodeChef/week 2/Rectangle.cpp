#include<bits/stdc++.h>
using namespace std;
/*

*/

bool comparator(pair<int,pair<int,int>>& a, pair<int,pair<int,int>>& b){
    if(a.second.first==b.second.first)
        return a.second.second<b.second.second;
    else
        return a.second.first<b.second.first;
}

void printStack(stack<pair<int,pair<int,int>>> s){
    cout<<" \n----------------------- printing stack -----------------------";
    while(!s.empty()){
        cout<<"idx "<<s.top().first<<" x: "<<s.top().second.first<<" y: "<<s.top().second.second<<"\n";
        s.pop();
    }
}

int main(){
    int n,a,b;
    cin>>n;
    vector<pair<int,pair<int,int>>> points;  //index,x coordinate,y coordinate
    for(int i=0;i<n;i++){
        cin>>a>>b;
        points.push_back({i,{a,b}});
    }
    // adding dummy O(n) data
    points.push_back({n,{1e5,0}});
    points.push_back({n+1,{0,0}});
    for(int i=0,j=n+2;i<=int(1e5);i++){
        points.push_back({j++,{i,500}});
    }
    // sort the points
    sort(points.begin(),points.end(),comparator);
    // for(int i=0;i<15;i++){
    //     cout<<"point i:  "<<points[i].first<<" -> "<<points[i].second.first<<":"<<points[i].second.second<<"\n";
    // }
    // vectors for left and right bound
    vector<int> leftBounds(points.size(),0),rightBounds(points.size(),0);
    int rightBoundIndx=0;
    // finding left bounds
    stack<pair<int,pair<int,int>>> stackForLeftBounds;// pair<xcoordinate,ycoordinate>
    stackForLeftBounds.push({points[0].first,{points[0].second.first,points[0].second.second}}); // it would be 0,0 origin
    // stack would always be in decreasing state from top to bottom
    for(int i=1;i<points.size();i++){
        while(!stackForLeftBounds.empty() and stackForLeftBounds.top().second.second>=points[i].second.second){
            stackForLeftBounds.pop();
        }
        if(!stackForLeftBounds.empty())
            leftBounds[points[i].first]=stackForLeftBounds.top().second.first;
        stackForLeftBounds.push({ points[i].first,{points[i].second.first,points[i].second.second}});
    }
    // stack for right bound
    stack<pair<int,pair<int,int>>> stackForRightBounds;
    for(int i=0;i<points.size();i++){
        // cin>>a;
        // cout<<"ith : "<<i<<" point is , idx is "<<points[i].first<<" x: "<<points[i].second.first<<" y: "<<points[i].second.second<<"\n";
        // printStack(stackForRightBounds);
        while(!stackForRightBounds.empty() and stackForRightBounds.top().second.second>points[i].second.second){
            rightBounds[stackForRightBounds.top().first]=points[i].second.first;
            // cout<<"setting rightBound of "<<stackForRightBounds.top().first<<" as "<<points[i].second.first<<"\n";
            stackForRightBounds.pop();
        }
        stackForRightBounds.push({points[i].first,{points[i].second.first,points[i].second.second}});
    }

    int maxProduct=0;
    // for(int i=0;i<15;i++){
    //     cout<<"bounds for "<<points[i].second.first<<":"<<points[i].second.second<<" and leftBound "<<leftBounds[points[i].first]<<" and rightBound "<<rightBounds[points[i].first]<<"\n";
    // }

    // calculate the areas
    for(int i=1;i<points.size();i++){
        maxProduct=max(maxProduct,points[i].second.second* (rightBounds[points[i].first]-leftBounds[points[i].first]));
    }
    cout<<maxProduct;
}