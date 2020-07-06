#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        // cout<<" test case running \n";
        int n,a,b;
        string one,two;
        cin>>n;
        int pointOfChef=0,pointOfMonty=0;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            one=to_string(a);
            two=to_string(b);
            a=0;b=0;
            for(int i=0;i<one.length();i++)
                a+=one[i]-'0';
            for(int i=0;i<two.length();i++)
                b+=two[i]-'0';
            if(a>b)
                pointOfChef++;
            else if(b>a)
                pointOfMonty++;
            else
                pointOfMonty++,pointOfChef++;
        }
        if(pointOfChef>pointOfMonty)
            cout<<"0 "<<pointOfChef<<"\n";
        else if(pointOfMonty>pointOfChef)
            cout<<"1 "<<pointOfMonty<<"\n";
        else
            cout<<"2 "<<pointOfChef<<"\n";
    }
    return 0;
}