#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,x;
    cin>>t;
    while(t--){
        cin>>x;
        int reverse=0;
        while(x){
            reverse=reverse*10 + x%10;
            x/=10;
        }
        cout<<reverse<<endl;
    }
}