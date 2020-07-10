#include<bits/stdc++.h>
using namespace std;

long long lcm(long long a,long long b){
    return (a*b)/(__gcd(a,b));
}

int solve(){
    /*
    
    for(long long i=1;i<=n;i++){
        if((i%a==0 and i%b!=0) or (i%b==0 and i%a!=0))
            count++;
    }
    if(count>=k)
        cout<<"Win\n";
    else
        cout<<"Lose\n";
    */
    // beautiful mathematics
    long long n,a,b,x,k,problemSolvedByA,problemSolvedByB,problemSolvedByBoth;
    cin>>n>>a>>b>>k;
    problemSolvedByA=n/a;
    problemSolvedByB=n/b;
    problemSolvedByBoth=n/(lcm(a,b));

    if (problemSolvedByA+problemSolvedByB- (2*problemSolvedByBoth) >=k )
        cout<<"Win\n";
    else
        cout<<"Lose\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}