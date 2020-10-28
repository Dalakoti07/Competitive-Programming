#include <bits/stdc++.h>
using namespace std;

void solve(){
    int arr[5][5];
    int x;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>x;
            if(x<1 || x>5){
                cout<<"INVALID INPUT";
                return;
            }
            arr[i][j]=x;
        }
    }
    int answers[5];
    int maxxy=-1;
    for(int i=0;i<5;i++){
        int count =0;
        for(int j=0;j<5;j++)
            if(arr[j][i]==1)
                count++;
        answers[i]=count;
        maxxy=max(maxxy,answers[i]);
    }

    for(int i=0;i<5;i++)
        if(answers[i]==maxxy){
            if(i==0)
                cout<<"Malaysia ";
            else if(i==1)
                cout<<"Australia ";
            else if(i==2)
                cout<<"Germany ";
            else if(i==3)
                cout<<"Dubai ";
            else   
                cout<<"France ";
        }

}

int main(){
    int t=1;
    while(t--)
        solve();
}