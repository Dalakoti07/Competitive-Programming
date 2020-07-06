#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n;
        map<int,int> verticalCount,horizontalCount;
        for(int i=0;i<4*n-1;i++){
            cin>>a>>b;
            if(verticalCount.count(b)==0)
                verticalCount[b]=1;
            else
                verticalCount[b]+=1;
            if(horizontalCount.count(a)==0)
                horizontalCount[a]=1;
            else
                horizontalCount[a]+=1;
        }

        // now find the missing x and y coordinate
        int reqX=-1,reqY=-1;
        // cout<<"\nfinding y\n";
        for(auto m :verticalCount){
            if(m.second%2){
                reqY=m.first;
                break;
            }
        }
        // cout<<"\nfinding x\n";
        for(auto m:horizontalCount){
            if(m.second%2){
                reqX=m.first;
                break;
            }
        }
        cout<<reqX<<" "<<reqY<<"\n";
    }
}