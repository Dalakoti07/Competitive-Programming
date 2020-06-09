#include<bits/stdc++.h>
using namespace std;


void fillTheMatrix(int arr[][1000],int size){
    int k=0,m=size-1,l=0,n=size-1,count=size*size;
    for(int value=1;k<=m and l<=n;){
        // cout<<"val :"<<value<<"\n";
        // print top row
        for(int i=l;i<=n;i++,value++)
            arr[k][i]=value;
        k++;
        // print right col
        for(int i=k;i<=m;i++,value++)
            arr[i][n]=value;
        n--;
        // print bottom row
        if(m>=k)
        for(int i=n;i>=l;i--,value++)
            arr[m][i]=value;
        m--;
        // print left col
        if(l<=n)
        for(int i=m;i>=k;i--,value++)
            arr[i][l]=value;
        l++;

        // cout<<"k:"<<k<<" l:"<<l<<" m:"<<m<<" n:"<<n<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n][1000];
        fillTheMatrix(arr,n);
        for(int i=0;i<n;i++,cout<<endl){
            for(int j=0;j<n;j++)
                cout<<arr[i][j]<<" ";
        }
    }
}