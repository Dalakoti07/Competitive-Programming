#include<bits/stdc++.h>
using namespace std;

void findRightValue(vector<vector<int>>& arr,int i,int j){
    // cout<<"asking for i: "<<i<<" j: "<<j<<endl;
    int row=arr.size(),col=arr[0].size();
    if(j+1<col and i+1<row){
        // top left cells
        int rightCount=0,bottomCount=0;
        cout<<"1 "<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+2<<"\n";// getting right scenario
        cin>>rightCount;
        cout<<"1 "<<i+1<<" "<<j+1<<" "<<i+2<<" "<<j+1<<"\n";// getting bottom scenario
        cin>>bottomCount;
        if(leftCount==1 and bottomCount==1){ //have to deal
            
        }
        else if(rightCount==0 or bottomCount==0)
            arr[i][j]=0;
        else if((rightCount==2 or bottomCount==2) or 
                    (rightCount==1 and bottomCount==2 or rightCount==2 and bottomCount==1))
            arr[i][j]=1;
    }else if(i+1<row and j+1==col){
        // right most col
        int leftCount=0,bottomCount=0;
        cout<<"1 "<<i+1<<" "<<j<<" "<<i+1<<" "<<j+1<<"\n";// getting left scenario
        cin>>leftCount;
        cout<<"1 "<<i+1<<" "<<j+1<<" "<<i+2<<" "<<j+1<<"\n";// getting bottom scenario
        cin>>bottomCount;
        if(leftCount==0 or bottomCount==0)
            arr[i][j]=0;
        else if((leftCount==2 or bottomCount==2) or 
                    (leftCount==1 and bottomCount==2 or leftCount==2 and bottomCount==1)
                    or (leftCount==1 and bottomCount==1))
            arr[i][j]=1;
    }
    else if(i+1==row){
        // dealing last row
        if(j+1<col){
            // non last col
            int rightCount=0,topCount=0;
            cout<<"1 "<<i+1<<" "<<j<<" "<<i+1<<" "<<j+1<<"\n";// getting right scenario
            cin>>rightCount;
            cout<<"1 "<<i<<" "<<j+1<<" "<<i+1<<" "<<j+1<<"\n";// getting top scenario
            cin>>topCount;
            if(rightCount==0 or topCount==0)
                arr[i][j]=0;
            else if((rightCount==2 or topCount==2) or 
                        (rightCount==1 and topCount==2 or rightCount==2 and topCount==1)
                        or (rightCount==1 and topCount==1))
                arr[i][j]=1;
        }else{
            // last col
            int leftCount=0,topCount=0;
            cout<<"1 "<<i+1<<" "<<j<<" "<<i+1<<" "<<j+1<<"\n";// getting left scenario
            cin>>leftCount;
            cout<<"1 "<<i<<" "<<j+1<<" "<<i+1<<" "<<j+1<<"\n";// getting top scenario
            cin>>topCount;
            if(leftCount==0 or topCount==0)
                arr[i][j]=0;
            else if((leftCount==2 or topCount==2) or 
                        (leftCount==1 and topCount==2 or leftCount==2 and topCount==1)
                        or (leftCount==1 and topCount==1))
                arr[i][j]=1;
        }
    }
    // cout<<"\nset the value to "<<arr[i][j]<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,p; 
        cin>>n>>p;
        vector<vector<int>> arr(n,vector<int>(n));
        int count =1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                findRightValue(arr,i,j);
            }
        }
        cout<<"2"<<endl;
        int verdict;
        for(int i=0;i<n;i++,cout<<endl)
            for(int j=0;j<n;j++)
                cout<<arr[i][j]<<" ";
        cin>>verdict;
        if(verdict==-1) return 0;
    }
}