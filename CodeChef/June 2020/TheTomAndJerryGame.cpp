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
            unsigned long long count =0;
            for(unsigned long long jerry=2;jerry<tom;jerry=jerry+2){
                int tomIter=tom,jerryIter=jerry;
                while(tomIter>=1 and jerryIter>=1){ // jerryIter wins , or , 
                    // cout<<"jerryIter :"<<jerryIter<<" tomIter :"<<tomIter<<endl;
                    if(jerryIter%2 == 0 and tomIter%2==1){
                        count++;
                        // cout<<"found: "<<jerryIter<<":"<<tomIter<<endl;
                        break;//jerryIter wins
                    }else if(jerryIter%2 ==0 and tomIter%2==0){
                        jerryIter/=2;
                        tomIter/=2;// one more round
                    }else if(jerryIter%2==1 and tomIter%2==0){
                        break;// tom wins
                    }else{
                        break;// tie
                    }
                }
            }
            cout<<count<<endl;
        }
 
    }
}