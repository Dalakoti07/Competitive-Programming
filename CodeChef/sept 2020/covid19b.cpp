#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define MOD 1e9+7
#define deb(x) cout<< #x << " = "<<x<<endl

using namespace std;

void init(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

// code from below

void solve(){
	int n;
    cin>>n;
    vi arr(n);
    FOR(i,n)
        cin>>arr[i];
    int count=0,Min=INT_MAX,Max=INT_MIN;
    set<int> peopleInfected;
    for(int i=0;i<n-1;i++){
        // deb(i);
        int infects=0;
        for(int j=i+1;j<n;j++){
            // check if athelete i and j infect each other
            int coeff_x_i=arr[i],coeff_x_j=arr[j];
            if(coeff_x_i<=coeff_x_j) // if i has same speed as j has then i wont catch j as j is standing ahead
                continue;
            else{
                // they would meet somehere, lets find where
                int coeff_net=coeff_x_i-coeff_x_j;
                int const_on_left=i+ (-1)*arr[i];
                int const_on_right=j+ (-1)*arr[j];
                int net_cost=const_on_right-const_on_left;
                if(net_cost<1){
                    continue;
                }else if(coeff_net!=0){
                    float inter=((float) net_cost) /( (float) coeff_net) ;
                    // deb(inter);
                    if(inter ==(int)inter){
                        // cout<<"i: "<<i<<" infected j: "<<j<<endl;
                        infects++;
                        peopleInfected.insert(j);
                    }
                }
            }
        }
        if(infects){
            // if we have some infects 
            peopleInfected.insert(i);
            Min=min(Min,(int) peopleInfected.size());
            Max=max(Max,(int) peopleInfected.size());
        }else{
            Min=min(1,Min);
            Max=max(1,Max);
        }
    }
    cout<<Min<<" "<<Max<<endl;
}

int main(){
    int t=1;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}