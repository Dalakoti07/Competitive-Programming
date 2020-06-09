#include<bits/stdc++.h>
using namespace std;

int go(int[] arr1,int idx1,int[] arr2,int idx2){
    if(idx1==3 or idx2==3)
        return 0;
    if (arr1[0]==arr2[0])
        return go(arr1+1,idx1+1,arr2+1,idx2);
    if(arr2[0]%arr1[0] ==0){
        return 1+min();// multiplying
    }
}

int main(){
    int t,x;
    cin>>t;
    while(t--){
        int arr1[3],arr2[3];
        for(int i=0;i<3;i++){
            cin>>x;
            arr1[i]=x;
        }
        for(int i=0;i<3;i++){
            cin>>x;
            arr2[i]=x;
        }
        cout<<go(arr1,arr2)<<endl;
    }
}