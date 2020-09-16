#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define FASTIO ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define MOD 1e9+7
#define deb(x) cout<< #x << " = "<<x<<endl;

using namespace std;

void init(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

// code from below
// binary search in real numbers 
/*
    More iteration means more precision. So for 100 iteration you can do normal binary search on integers or 
    array of size 2^100. But when you are doing binary search on real number then you are dividing 
    range into parts. so you are basically dividing range of length 2* 10^9 (in this question) into 
    2^100 segments of length (2* 10^9 )/(2^100) and applying binary search on them 
    so more the iteration smaller will be the length of each segment hence more precise will be the answer.


    infact in this question instead of 100, 60 iterations will give accuaracy upto 10^9

*/

// hint for Binary search if we can kill all aliens with c cool time then we can surely kill them with cool time less than c

long long N, D;
vector<long long> appear_time;
bool isPossible(long double cool_time){
    // greedily we will shoot the aliens which come first ( and they take same time to reach earth so sort arrivals of all alliens) as why waste time and then let cannon cool down
    long double time_stamp=0.0;
    for(int i=0;i<N;i++){
        if(time_stamp<appear_time[i]){
            // means allien is about to come, and thus we shoot him and then let the cannon cool down 
            time_stamp=appear_time[i]+cool_time;
        }else if(time_stamp<= appear_time[i]+D){
            // means allien has already arrived and allien is on the way to reach earth shoot him and cool down
            time_stamp+=cool_time;
        }else{
            // if timestamp > appeartime[i]+D, means allien has reached earth and u lose
            return false;
        }
    }
    return true;
}

void solve(){
    // one way to do it run loop till 100 iteration as it would give precision for about 10^6
    // and another way is until r-l is <10^6
    cin>>N>>D;
    appear_time.clear();
    appear_time.resize(N);
    for(int i=0;i<N;i++)
        cin>>appear_time[i];
    sort(appear_time.begin(),appear_time.end());
    long double start=0.0,end=2 *(1e9),mid;
    while((end-start)>=0.000000001){
        mid=(end+start)/2.0;
        if(isPossible(mid))
            start=mid;
        else end=mid;
    }
    cout<<fixed<<setprecision(10)<<start<<endl;
}

int main(){
    int t=1;
    cin>>t;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--)
        solve();
}