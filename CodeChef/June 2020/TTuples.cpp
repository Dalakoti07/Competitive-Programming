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

inline ll mulFac(ll a,ll b,ll c, ll d){
    if(b!=a and (d-c)%(b-a)==0)
        return (d-c)/(b-a);
    return 1;
}

inline bool equal(ll* a,ll* b){
    FOR(i,3) if(a[i]!=b[i]) return false;
    return true;
}

int best;
void solve(ll* a, ll* b, int num=0){
    if(num>=best) return;
    if(equal(a,b)){
        best=min(best,num);
        return ;
    }
    if(num>=2) return;

    set<ll> add;// set containing all possible options which can be added 
    add.insert(b[0]-a[0]);
    add.insert(b[1]-a[1]);
    add.insert(b[2]-a[2]);

    set<ll> mult;// set containing all possible options which can be multiplied
    FOR(i,3) if(a[i]!=0 and b[i]%a[i]==0)
        mult.insert(b[i]/a[i]);
    
    mult.insert(mulFac(a[0],a[1],b[0],b[1]));
    mult.insert(mulFac(a[2],a[1],b[2],b[1]));
    mult.insert(mulFac(a[0],a[2],b[0],b[2]));
    mult.insert(0);

    FORE(mask,1,7){
        vi all;
        FOR(j,3) 
            if(mask&(1<<j)) 
                all.pb(j);
        // cout<<" printing all\n";
        // for(auto i:all)
        //     cout<<i<<" ";
        // cout<<endl;
        for(auto x: add){
			ll aa[3];
			FOR(j,3)aa[j] = a[j];
			for(auto e: all)aa[e]+=x;
			solve(aa,b,num+1);
		}
		for(auto x:mult){
			ll aa[3];
			FOR(j,3)aa[j] = a[j];
			for(auto e: all)aa[e]*=x;
			solve(aa,b,num+1);
		}
    }

}


int solve(){
    best =3;
    ll a[3];
    ll b[3];
    cin>>a[0]>>a[1]>>a[2];
    cin>>b[0]>>b[1]>>b[2];

    solve(a,b);
    cout<<best<<endl; 
}

int main(){
    FASTIO;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}