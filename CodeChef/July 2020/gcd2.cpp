#include <bits/stdc++.h>
using namespace std;
// use python in this case 
/*
# cook your dish here
from math import gcd
t=int(input())
while(t>0):
    a,b= map(int,input().split())
    print(gcd(a,b))
    t-=1
*/

long long reducedB(long long a,string b){
    long long ans=0;
    for(int i=0;i<b.length();i++){
        ans= ((ans*10) +(b[i]-'0'))%a;
    }
    return ans;
}

void findLargeGCD(long long a,string b){
    if(a==0){ 
        cout<<b<<endl;
        return;
    }
    long long bR=reducedB(a,b);
    long long ans = __gcd(a,bR);
    cout<<ans<<endl;
}

int solve(){
	long long a;
    cin>>a;
    string b;
    cin>>b;
    findLargeGCD(a,b);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}