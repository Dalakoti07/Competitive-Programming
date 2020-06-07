#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int g;
        cin>>g;
        while(g--){
            int I,n,Q,ans=0;
            cin>>I>>n>>Q;
            n+=1;
            bool firstIsHead=false,toBeSearchedIsHead=false;
            if(I==1) firstIsHead=true;
            if(Q==1) toBeSearchedIsHead=true;
            string afterNRoundsFirstElement;
            if(n%2==1){                
                if(firstIsHead){
                    afterNRoundsFirstElement="head";
                }else{
                    afterNRoundsFirstElement="tail";
                }
                n--;
                ans=n/2;
                // afterNRoundsFirstElement=firstIsHead;
            }else{
                // afterNRoundsFirstElement=!firstIsHead;
                if(firstIsHead){
                    afterNRoundsFirstElement="tail";
                    if(toBeSearchedIsHead){
                        n--;
                        ans=n/2;
                    }else{
                        n--;
                        ans=n/2 + 1;
                    }
                }else{
                    afterNRoundsFirstElement="head";
                    if(toBeSearchedIsHead){
                        n--;
                        ans=n/2 +1;
                    }else{
                        n--;
                        ans=n/2;
                    }
                }                
            }
            cout<<ans<<endl;
        }
    }
}