#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int acts,laddus=0;
        string studentType,activityType;
        cin>>acts>>studentType;
        while(acts--){
            cin>>activityType;
            if(activityType=="TOP_CONTRIBUTOR" or activityType=="CONTEST_HOSTED"){
                if(activityType=="TOP_CONTRIBUTOR") laddus+=300;
                else laddus+=50;
            }else{
                int x;
                cin>>x;
                if(activityType=="CONTEST_WON"){
                    if(x<20)
                        laddus+=300+ 20-x;
                    else
                        laddus+=300;
                }else{
                    laddus+=x;// severity 
                }
            }
        }
        if(studentType=="INDIAN"){
            cout<<laddus/200<<endl;
        }else{
            cout<<laddus/400<<endl;
        }
    }
}