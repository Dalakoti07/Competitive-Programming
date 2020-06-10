#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int arr1[3],arr2[3];
        int dp[3],additionArray[3],multiplicationArray[3];
        for(int i=0;i<3;additionArray[i]=0,multiplicationArray[i]=0,dp[i]=0 ,i++)
            cin>>arr1[i];
        for(int i=0;i<3;i++)
            cin>>arr2[i];

        // filling i =2 
        if(arr2[2]!=arr1[2]){
            if(arr1[2]!=0)
            if(arr2[2]%arr1[2]==0){
                multiplicationArray[2]=arr2[2]/arr1[2];
            }
            additionArray[2]=arr2[2]-arr1[2];
            dp[2]=1;
        }
        // filling the 1st index i.e i=1
        if(arr1[1]==arr2[1]){
            multiplicationArray[1]=0;additionArray[1]=0;
            dp[1]=dp[2];
        }else{
            if(arr1[1]+additionArray[2] ==arr2[1] ){
                dp[1]=dp[2];
                additionArray[1]=additionArray[2];
            }else if(arr1[1]*multiplicationArray[2] ==arr2[1] ){
                dp[1]=dp[2];
                multiplicationArray[1]=multiplicationArray[2];
            }else{
                dp[1]=1+dp[2];
                additionArray[1]=arr2[1]-arr1[1];
                if(arr1[1]!=0)
                multiplicationArray[1]=arr2[1]/arr1[1];
            }
        }

        // filling 0th index
        if(arr2[0]==arr1[0] or arr1[0]+additionArray[1] ==arr2[0] or arr1[0]+additionArray[2] ==arr2[0] ){
            if(arr1[0]+additionArray[2] ==arr2[0]){
                if(dp[1]==dp[2] and multiplicationArray[1]==multiplicationArray[2]){
                    // means multiplication option picked by i =1
                    if(multiplicationArray[1]!=0)
                        dp[0]=1+dp[1];
                    else
                        dp[0]=dp[1];
                }
            }else
                dp[0]=dp[1];
        }
        else if(arr2[0]==arr1[0] or arr1[0]*multiplicationArray[1] == arr2[0] or arr1[0]*multiplicationArray[2] ==arr2[0] ){
            if(arr1[0]*multiplicationArray[2] ==arr2[0]){
                if(dp[1]==dp[2] and additionArray[1]==additionArray[2]){
                    // means addition option picked by i =1
                    dp[0]=1+dp[1];
                }
            }else
                dp[0]=dp[1];
        }else{
            dp[0]=1+dp[1];
        }
        // /*
        cout<<"\ndp array:\n";
        for(int i=0;i<3;i++){
            cout<<dp[i]<<" ";
        }
        cout<<"\nadd arr array:\n";
        for(int i=0;i<3;i++){
            cout<<additionArray[i]<<" ";
        }
        cout<<"\nmul array:\n";
        for(int i=0;i<3;i++){
            cout<<multiplicationArray[i]<<" ";
        }
        cout<<endl;
        //*/

        cout<<dp[0]<<endl;
    }
}