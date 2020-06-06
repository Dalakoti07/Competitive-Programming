#include<bits/stdc++.h>
using namespace std;
// partially accepted, I dont know why, refer editorials
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
       int n,x;
       long long int moneyWithChef=0;
       cin>>n;
       vector<int> moneys;
       for(int i=0;i<n;i++){
           cin>>x;
           moneys.push_back(x);
       }
       bool ans=true;
       for(int i=0;i<n;i++){
            // cout<<"cust with:"<<moneys[i]<<" Money with chef at:"<<i<<" "<<moneyWithChef;
            int amountToBeReturn=moneys[i]-5;
            if(amountToBeReturn > moneyWithChef){
                // cout<<"in succefient amount\n";
                ans=false;
                break;
            }else{
                if(moneys[i]>5){
                    moneyWithChef-=amountToBeReturn; //net gain
                }
                else {
                    moneyWithChef+=5;
                }
                // cout<<" after trans: "<<moneyWithChef<<endl;
            }
       }
       if(ans){
           cout<<"YES"<<endl;
       }else{
           cout<<"NO"<<endl;
       }
    }
}