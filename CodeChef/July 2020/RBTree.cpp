#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define MOD 1000000007

using namespace std;

void init(){
  FASTIO;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}
int LCA(int x,int y){
    int ans=1;
    set<int> one,two;
    while(x>0){
        one.insert(x/2);
        x/=2;
    }
    while(y>0){
        two.insert(y/2);
        y/=2;
    }
    for(auto i:one){
        if(two.find(i)!=two.end())
            ans=max(ans,i);
    }
    return ans;
}

int countNode(int x){
    int count=0;
    while(x>0){
        count++;
        x/=2;
    }
    return count;
}

int countNodesBT(int x,int y){
    return countNode(x)+countNode(y)-(2*countNode(LCA(x,y)))+1;
}

void solve(){
    int q,r,b,x,y;
    b=1,r=0;
    cin>>q;
    string s;
    while(q--){
        cin>>s;
        if (s=="Qi"){
       	    swap(r,b);
        }
        else{
            cin>>x>>y;
            if (countNodesBT(x,y)%2==0)
                cout<<countNodesBT(x,y)/2<<"\n";
            else{
                    ll odd=countNodesBT(x,y)/2 + 1;
                    ll even = countNodesBT(x,y)/2;
                    if (s=="Qb"){
                        if (b==countNode(x)%2)
                            cout<<odd<<"\n";
                        else
                            cout<<even<<"\n";
                    }
                    else{
                        if (r==countNode(x)%2)
                            cout<<odd<<"\n";
                        else
                            cout<<even<<"\n";
                    }
            }
       }
    }
}

int main(){
    // createTree(root,1);
    int q=1;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(q--){
        solve();
    }
}