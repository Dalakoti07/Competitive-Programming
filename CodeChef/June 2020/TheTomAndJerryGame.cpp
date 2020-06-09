#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        unsigned long long tom;
        cin>>tom;
        if(tom%2==1){
            // find all evens count that is answer
            cout<<tom/2<<endl; 
        }else{
            // pattern ,if we find first number, then all others are mutiple of it 
            unsigned long long count=2,copy=tom;
            while(tom%2==0){
                tom/=2;
                count*=2;
            }
            cout<<copy/count<<endl;
        }
    }
}