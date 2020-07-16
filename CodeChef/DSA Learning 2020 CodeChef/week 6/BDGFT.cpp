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

// first I thought complexity would be high but it worked

int solve(){
    int n;
    string str;
    cin>>str;
    n=str.length();

    vector<int> count1(n+1,0),count0(n+1,0);
    count1[1]=str[0]=='1';
    count0[1]=str[0]=='0';
    for(int i=1;i<n;i++){
        if(str[i]=='0')
            count0[i+1]=count0[i]+1;
        else
            count0[i+1]=count0[i];
        if(str[i]=='1')
            count1[i+1]=count1[i]+1;
        else
            count1[i+1]=count1[i];
    }
    int disc=1- (4*-1*n);
    disc=sqrt(disc);
    int root1=(-1+disc)/2;
    // find all the substring from which have 1count as x and total length as x^2 and x
    int count=0;
    for(int i=root1;i>=1;i--){
        int subLen=i+ pow(i,2);
        int zCount,oCount;
        for(int i=0;i<=n-subLen;i++){
            zCount= count0[i+subLen]-count0[i];
            oCount= count1[i+subLen]-count1[i];
            if(zCount==pow(oCount,2))
                count++;
        }
    }
    cout<<count<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}