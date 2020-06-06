#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string students;
        cin>>students;
        int ans=0; 
        int n =students.length();
        if(n==0 or n==1){
            ans=0;
        }else{
            for(int i=1;i<n;i++){
                if(students[i]=='x' and students[i-1]=='y'){
                    ans++;
                    students[i]='d';// 'd' denotes this student has been counted      
                }else if(students[i]=='y' and students[i-1]=='x'){
                    ans++;
                    students[i]='d';
                }
            }
        }
        cout<<ans<<"\n";
    }
}