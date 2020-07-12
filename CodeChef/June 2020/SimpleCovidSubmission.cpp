#include<bits/stdc++.h>
using namespace std;

void askJudge(int row1,int col1, int row2, int col2, vector<vector<int>>& arr){
    int x;
    cout<<"1 "<<row1<<" "<<col1<<" "<<row2<<" "<<col2<<"\n";
    cin>>x;
    if(x==-1)
        exit(0);
    arr[row1-1][col1-1]=x;
}

void fillTheRow(int r,vector<vector<int>>& arr,int n){
    int row=r+1;
    int col1=1,col2=n;
    for(int i=1;i<=col2;i++)
        askJudge(row,i,row,i,arr);
}

int main(){
    int t,x;
    cin>>t;
    while(t--){
        int n,prob;
        cin>>n>>prob;
        vector<vector<int>> arr(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
            fillTheRow(i,arr,n);
        cout<<"2\n";
        for(int i=0;i<n;i++,cout<<"\n")
            for(int j=0;j<n;j++)
                cout<<arr[i][j]<<" ";
        cin>>x;
        if(x==-1){
            return 0;
        };
    }
}