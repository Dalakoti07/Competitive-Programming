#include <bits/stdc++.h>
using namespace std;

void solve(){
    string input;
    int count=0,bcount=0;
    map<int,int> unique;
    while(1){
        cin>>input;
        if(input[0]=='q')
            break;
        for(int i=0;i<input.size();i++)
            if(input[i]>='0' && input[i]<='9')
                unique[input[i]-'0']++;
        count++;
    }
    cout<<"BLANK KEYS: "<<bcount<<endl;
    cout<<"TOTAL KEYS: "<<unique.size()<<endl;
    cout<<"NUMBER OF LOCKS: "<<count<<endl;
}

int main(){
    int t=1;
    while(t--)
        solve();
}