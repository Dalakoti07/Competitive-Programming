#include<bits/stdc++.h>
using namespace std;

vector<int> allPrimes;
vector<int> coPrimes;
vector<int> allValidPoints;

void precompute(){
    // cout<<"pre compute ";
    allPrimes.push_back(2);
    allPrimes.push_back(3);
    for(int i=5;i<=200;i=i+2){
        // if i is prime
        bool isPrime=true;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                isPrime=false;
                break;
            }
        }
        if(isPrime)
            allPrimes.push_back(i);
    }
    int len=allPrimes.size();
    for(int i=0;i<len-1;i++)
        for(int j=i+1;j<len;j++)
            if(allPrimes[i]*allPrimes[j]<=200)
                coPrimes.push_back(allPrimes[i]*allPrimes[j]);
    sort(coPrimes.begin(),coPrimes.end());
    len =coPrimes.size();
    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++){
            allValidPoints.push_back(coPrimes[i]+coPrimes[j]);
        }
    }
}

void solve(){
    int n;
    cin>>n;
    // if(find(allValidPoints.begin(),allValidPoints.end(),n/2)!=allValidPoints.end()){
    //     cout<<"YES\n";return;
    // }
    if(find(allValidPoints.begin(),allValidPoints.end(),n)!=allValidPoints.end()){
        cout<<"YES\n";return;
    }
    cout<<"NO\n";
}

int main(){
    int t;
    cin>>t;
    precompute();
    while(t--){
        solve();
    }
}