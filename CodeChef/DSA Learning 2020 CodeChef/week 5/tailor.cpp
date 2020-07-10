#include<bits/stdc++.h>
using namespace std;

int go(int l,int b){
    return __gcd(l,b);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int l,b;
        cin>>l>>b;
        cout<<go(l,b)<<"\n";
    }
}

/*
    int area=l*b;
    int n=1,ans;
    int ratio=area/n,iRoot;
    double dRoot;
    while(ratio!=0 and n<area){
        if(area%n==0){
            dRoot=sqrt(ratio);
            iRoot=(int)dRoot;
            if(dRoot-iRoot ==0){
                ans=iRoot;
                cout<<"updated side: "<<ans<<" for n = "<<n<<"\n";
            }
        }
        n++;
        ratio=area/n;
    }
    return ans;
    */
    // with above simulation and editorial, we can say that 
    /*
    10
    30 30
    updated side: 30 for n = 1
    updated side: 15 for n = 4
    updated side: 10 for n = 9
    updated side: 6 for n = 25
    updated side: 5 for n = 36
    updated side: 3 for n = 100
    updated side: 2 for n = 225
    2
    40 50
    updated side: 20 for n = 5
    updated side: 10 for n = 20
    updated side: 5 for n = 80
    updated side: 4 for n = 125
    updated side: 2 for n = 500
    2
    30 40
    updated side: 20 for n = 3
    updated side: 10 for n = 12
    updated side: 5 for n = 48
    updated side: 4 for n = 75
    updated side: 2 for n = 300
    2
    20 20
    updated side: 20 for n = 1
    updated side: 10 for n = 4
    updated side: 5 for n = 16
    updated side: 4 for n = 25
    updated side: 2 for n = 100
    2
    */
    // we can see that n increases but side length increase reach peak and then falls this peak is common multiple of L and B
    