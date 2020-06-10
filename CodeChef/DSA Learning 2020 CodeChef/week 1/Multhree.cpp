#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        // there is cyclic nature of power of 2 and we have GP here
        unsigned long long n,a,b;
        cin>>n>>a>>b;
        // cycle is like this a, b, a+b,[2(a+b)mod, 4(a+b)mod,8(a+b)mod,6(a+b)mod ](1st cycle) ,[2(a+b)mod, 4(a+b)mod,
        //8(a+b)mod ,6(a+b)mod ](2nd cycle),......
        if(n==2){
            cout<< (a+b)%10<<endl;
        }else{
            unsigned long long totalCompleteCycle= (n-3 )/4;
            unsigned long long isLastElementOfIncompleteCycle=(n-3)%4;
            unsigned long long valueOfOneCycle= ( 2*(a+b) )%10 +( 4*(a+b) )%10+( 8*(a+b) )%10+( 6*(a+b) )%10; 
            unsigned long long int sumOfAllDigits= totalCompleteCycle * valueOfOneCycle;
            sumOfAllDigits+=(2*((a+b)%10));
            if(isLastElementOfIncompleteCycle==1){
                sumOfAllDigits+=( 2*(a+b) )%10 ;
            }else if(isLastElementOfIncompleteCycle==2){
                sumOfAllDigits+=( 2*(a+b) )%10 +( 4*(a+b) )%10;
            }else if(isLastElementOfIncompleteCycle==3){
                sumOfAllDigits+=( 2*(a+b) )%10 +( 4*(a+b) )%10+( 8*(a+b) )%10;
            }
            // cout<<sumOfAllDigits<<" ans: ";
            if(sumOfAllDigits%3==0)
                cout<<"YES"<<endl;
            else 
                cout<<"NO"<<endl;
        }
    }
}