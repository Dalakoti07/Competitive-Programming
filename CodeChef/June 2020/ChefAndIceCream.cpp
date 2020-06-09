#include<bits/stdc++.h>
using namespace std;
// partially accepted, I dont know why, refer editorials
int main(){
    int t;
    cin>>t;
    while(t--){
       int n,x;
       int FiveRupeeCoins=0,TenRupeeCoins=0;
       cin>>n;
       vector<int> moneys;
       for(int i=0;i<n;i++){
           cin>>x;
           moneys.push_back(x);
       }
       bool ans=true;
       for(int i=0;i<n;i++){
            if(moneys[i]==5){
                FiveRupeeCoins++;
            }else if(moneys[i]==10){
                if(FiveRupeeCoins>0){
                    FiveRupeeCoins--;
                    TenRupeeCoins++;
                }else{
                    ans=false;break;
                }
            }else{
                if(TenRupeeCoins>0){
                    TenRupeeCoins--;
                }
                else if(FiveRupeeCoins>=2){
                    FiveRupeeCoins-=2;
                }else{
                    ans=false;break;
                }
            }
       }
       if(ans){
           cout<<"YES"<<endl;
       }else{
           cout<<"NO"<<endl;
       }
    }
}