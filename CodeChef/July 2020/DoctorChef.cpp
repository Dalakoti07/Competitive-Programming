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

/*
    What the hell went wrong
    unable to generalise the idea and not experimenting
    Practise greedy
*/


void init(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

int solve(){
    int n,x;
    cin>>n>>x;
    vector<int> countries(n);
    for(int i=0;i<n;i++)
        cin>>countries[i];
    sort(countries.begin(),countries.end());
    auto itr=lower_bound(countries.begin(),countries.end(),x);
    int startIdx=itr-countries.begin();
    int days=0,caseOne=0;
    // checking what would be answer if we start from this country and serve the greater countries ahead, and then at last all
    // smaller countries would be served in 1 days
    for(int i=startIdx;i<n;i++){
        if(x<countries[i]){
            while(x<countries[i]){
                x*=2;
                days++;
            }
            days++;
        }else{
            days++;
        }
        x=2*countries[i];
    }
    caseOne= days+startIdx ;// because we are curring big companies first and then next big companies and when all this is done
    // we can cure small countries in one day

    // covering a edge case that given 4 countries 30,40,80 and 180 and k=60 start with lowerbound would give 6
    // but starting from a element before lowerbound would give better answer which is 5
    days=0;
    int caseTwo=0;
    if(startIdx!=0){
        startIdx--;
        for(int i=startIdx;i<n;i++){
            if(x<countries[i]){
                while(x<countries[i]){
                    x*=2;
                    days++;
                }
                days++;
            }else{
                days++;
            }
            x=2*countries[i];
        }
        caseTwo=days+startIdx;
        cout<<min(caseTwo,caseOne)<<endl;
    }else{
        cout<<caseOne<<endl;
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}