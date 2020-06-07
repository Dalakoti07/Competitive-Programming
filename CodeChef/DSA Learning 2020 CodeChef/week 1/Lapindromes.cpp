#include<bits/stdc++.h>
using namespace std;

void print(map<char,int> m){
    map<char, int>::iterator itr; 
    for (itr = m.begin(); itr != m.end(); ++itr) { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
    cout<<"\n"
;}

int main(){
    int t;
    string x;
    cin>>t;
    while(t--){
        map<char,int> m1,m2;
        cin>>x;
        int n= x.length();
        int mid = (n%2==0)? n/2 : n/2 +1;
        for(int i=0,j=mid;j<n;j++,i++){
            if(m1.count(x[i])){
                m1[x[i]]+=1;
            }else{
                m1[x[i]]=1;
            }
            if(m2.count(x[j])){
                m2[x[j]]+=1;
            }else{
                m2[x[j]]=1;
            }
        }
        /*cout<<"m1\n";
        print(m1);
        cout<<"m2\n";
        print(m2);*/
        if(m1==m2){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    
}