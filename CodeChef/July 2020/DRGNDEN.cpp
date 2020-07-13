#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back

using namespace std;

ll go(vector<ll>& heights,vector<ll>& spices,int n,int start,int end){
    bool leftToRight=(start<end)? true:false;
    start--;
    end--;
    ll taste=0,startHeight,endHeight=heights[end];
    if(leftToRight){
        startHeight=heights[end];
        // come from left to right we can skip a node if its valley
        taste+=spices[end];
        bool possible=false;
        for(int i=end;i>start;i--){
            // cout<<" at i: "<<i<<" and height(i-1) is "<<heights[i-1]<<" and stratHt : "<<startHeight<<endl;
            if(heights[i-1]>startHeight){
                if(i-1==start)
                    possible=true;
                taste+=spices[i-1];
                // cout<<"adding "<<spices[i-1]<<" in bucket ";
                startHeight=heights[i-1];
            }
            else{
                continue;
            }
        }
        if(!possible)
            cout<<"-1\n";
        else
            cout<<taste<<endl;
    }else{//right to left
        // come from right to left
        // (think backwards ) find if its possible that from left to right that we can fly only high and high from end and reach start 
        taste+=spices[end];
        bool possible=false;
        startHeight=heights[end];
        for(int i=end;i<start;i++){
            if(heights[i+1]>startHeight){
                if(i+1==start)
                    possible=true;
                taste+=spices[i+1];
                // cout<<"adding "<<spices[i+1]<<" in bucket ";
                startHeight=heights[i+1];
            }
            else{
                continue;// skipping the node
            }
        }
        if(!possible)
            cout<<"-1\n";
        else
            cout<<taste<<endl;
    }
}

int solve(){
    // FASTIO;
    int n,q;
    cin>>n>>q;
    vector<ll> heights(n),spices(n);
    for(int i=0;i<n;i++)
        cin>>heights[i];
    for(int i=0;i<n;i++)
        cin>>spices[i];
    while(q--){
        int type,a,b;
        cin>>type>>a>>b;
        if(type==2){
            // find ans
            go(heights,spices,n,a,b);
        }else{
            spices[a-1]=b;
        }
    }
}

int main(){
    int t;
    t=1;
    while(t--){
        solve();
    }
}